/* ************************************************************************** */
/* ******************************  LIBRARIES  ******************************* */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/* *******************************  FUNCTIONS  ****************************** */
/* ************************************************************************** */

std::map<std::string, std::string>* init_db_from_file(void)
{
    std::map<std::string, std::string>*     data_map;
    std::ifstream                           input("data.csv");
    std::string                             line, key, value;

     if (input.fail())
        return NULL;
    data_map = new std::map<std::string, std::string>;
    while (std::getline(input, line))
    {
        if (line.find("date") != std::string::npos)
            continue;
        key = line.substr(0, line.find(','));
        value = line.substr(line.find(',') + 1, line.length());
        (*data_map).insert(std::make_pair(key, value));
    }
    return data_map;
}

/* ************************************************************************** */

static std::string trim(std::string str, char c)
{
    size_t first = str.find_first_not_of(c);
    if (first == std::string::npos)
        return str;
    size_t last = str.find_last_not_of(c);
    return str.substr(first, last - first + 1);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static int days_in_month(int year, int month)
{
    switch (month)
    {
        case 2:
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                return 29;
            else
                return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static void is_valid_date_format(std::string& date_str)
{
    std::tm tm = {};
    std::istringstream iss(date_str);

    iss >> std::get_time(&tm, "%Y-%m-%d");
    if (iss.fail())
        throw std::invalid_argument("Error: invalid date format.");
    if (tm.tm_year < 100 || tm.tm_year > 123 ||
        tm.tm_mon < 0 || tm.tm_mon > 11 ||
        tm.tm_mday < 1 || tm.tm_mday > days_in_month(tm.tm_year, tm.tm_mon+1))
    {
        throw std::invalid_argument("Error: invalid date value.");
    }
    std::time_t t = std::mktime(&tm);
    if (t == -1)
        throw std::invalid_argument("Error: invalid date format. ");
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static void is_positive_number( std::string& number)
{
    bool dot_found = false;
    for (size_t i = 0; i < number.length(); i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            if (number[i] == '.' && i != 0 && i != number.length() - 1 && \
                !dot_found)
            {
                dot_found = true;
                continue;
            }
            throw std::invalid_argument("Error: not a positive number.");
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static void is_smaller_than_or_equal_to_1000(std::string& number)
{
    int my_number;

    try
    {
        if (number.find('.') != std::string::npos)
            my_number = std::stoi(number.substr(0, number.find('.')));
        else
            my_number = std::stoi(number);
    }
    catch(const std::exception& e)
    {
        throw std::out_of_range("Error: too large a number.");
    }
    if (my_number > 1000)
        throw std::out_of_range("Error: too large a number.");
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static std::string*    split_input(std::string& input_line)
{
    std::string* internal = new std::string[2];
    std::stringstream ss(input_line, std::ios_base::in);
    std::string token;
    int index = 0;

    while(getline(ss, token, '|') && index <= 2)
    {
        internal[index++] = trim(token, ' ');
        if (((ss.eof() && index == 1)) || (!ss.eof() && index == 2))
            throw std::invalid_argument("Error: bad input => " + input_line);
    }
    return internal;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static void search_and_calculate_average(std::string& date, std::string& value, 
        std::map<std::string, std::string>* data_map)
{
    int db_int_value = -1;
    int input_int_value = -1;
    float db_float_value = -1;
    float input_float_value = -1;
    std::map<std::string, std::string>::iterator it;
    
    it = (*data_map).find(date);
    if (it == (*data_map).end())
    {
        it = (*data_map).lower_bound(date);
        if (it != data_map->begin())
            it--;
    }

    if (value.find('.') != std::string::npos)
        input_float_value = std::stof(value);
    else
        input_int_value = std::stoi(value);

    if (it->second.find('.') != std::string::npos)
        db_float_value = std::stof(it->second);
    else
        db_int_value = std::stoi(it->second);
    std::cout << date << " => " << value << " => " << \
        (db_int_value >= 0 ? db_int_value : db_float_value) \
        * (input_int_value >= 0 ? input_int_value : input_float_value) \
        << std::endl;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

int read_input_file(std::string file_name, 
        std::map<std::string, std::string>* data_map)
{
    std::ifstream file(file_name);
    std::string line;
    std::string* internal;

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return EXIT_FAILURE;
    }
    else if (getline(file, line) && line != "date | value")
    {
        std::cerr << "Error: invalid titles." << std::endl;
        return EXIT_FAILURE;
    }
    while (getline(file, line))
    {
        try
        {
            internal = split_input(line);
            is_valid_date_format(internal[0]);
            is_positive_number(internal[1]);
            is_smaller_than_or_equal_to_1000(internal[1]);
            search_and_calculate_average(internal[0], internal[1], data_map);
            delete [] internal;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    file.close();
    return EXIT_SUCCESS;
}
