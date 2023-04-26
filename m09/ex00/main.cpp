/* ************************************************************************** */
/* ******************************  LIBRARIES  ******************************* */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
/* *********************************  MAIN  ********************************* */
/* ************************************************************************** */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return EXIT_FAILURE;
    }
    std::map<std::string, std::string>* data_map = init_db_from_file();
    if (data_map == NULL)
    {
        std::cout << "Error: failed to initialize the database." << std::endl;
        return EXIT_FAILURE;
    }
    if (read_input_file(argv[1], data_map) == EXIT_FAILURE)
    {   
        delete data_map;
        return EXIT_FAILURE;
    }
    delete data_map;
    return EXIT_SUCCESS;
}
