/* ************************************************************************** */
/* ******************************  LIBRARIES  ******************************* */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/* *******************************  FUNCTIONS  ****************************** */
/* ************************************************************************** */

bool    string_has_only_positive_integers(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
} 

/* ********************************* VECTOR ********************************* */

static void    print_vector_array(std::string step, std::vector<int>* array)
{
    std::cout << step;
    for (size_t i = 0; i < array->size(); i++)
        std::cout << array->at(i) << " ";
    std::cout << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static std::vector<int>*   vector_insertion_sort(std::vector<int>* input)
{
    size_t  i = 0;
    size_t  j;
    int     temp;
    while (++i < input->size())
    {
        j = i;
        while (j > 0 && (*input)[j - 1] > (*input)[j])
        {
            temp = (*input)[j];
            (*input)[j] = (*input)[j - 1];
            (*input)[j - 1] = temp;
            j--;
        }
    }
    return input;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static std::vector<int>*   vector_merge(std::vector<int>* left, std::vector<int>* right)
{
    std::vector<int>*   result = new std::vector<int>;
 
    while (left->size() > 0 && right->size() > 0)
    {
        if (left->at(0) <= right->at(0))
        {
            result->push_back(left->at(0));
            left->erase(left->begin());
        }
        else
        {
            result->push_back(right->at(0));
            right->erase(right->begin());
        }
    }
    while (left->size() > 0)
    {
        for (size_t i = 0; i < left->size(); i++)
            result->push_back(left->at(i));
        break;
    }
    while (right->size() > 0)
    {
        for (size_t i = 0; i < right->size(); i++)
            result->push_back(right->at(i));
        break;
    }
    delete left;
    delete right;
    return result;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static std::vector<int>*   vector_merge_sort(std::vector<int>* input, size_t threshold)
{
    if (input->size() <= threshold)
        return vector_insertion_sort(input);
    size_t mid = input->size() / 2;

    std::vector<int>*   left = new std::vector<int>;
    for (size_t i = 0; i < mid; i++)
        left->push_back(input->at(i));

    std::vector<int>*   right = new std::vector<int>;
    for (size_t i = mid; i < input->size(); i++)
        right->push_back(input->at(i));

    delete input;
    left = vector_merge_sort(left, threshold);
    right = vector_merge_sort(right, threshold);

    return vector_merge(left, right);
}

/* ********************************* DEQUE ********************************** */

static std::deque<int>*   deque_insertion_sort(std::deque<int>* input)
{
    size_t  i = 0;
    size_t  j;
    int     temp;
    while (++i < input->size())
    {
        j = i;
        while (j > 0 && (*input)[j - 1] > (*input)[j])
        {
            temp = (*input)[j];
            (*input)[j] = (*input)[j - 1];
            (*input)[j - 1] = temp;
            j--;
        }
    }
    return input;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static std::deque<int>*   deque_merge(std::deque<int>* left, std::deque<int>* right)
{
    std::deque<int>*   result = new std::deque<int>;
 
    while (left->size() > 0 && right->size() > 0)
    {
        if (left->at(0) <= right->at(0))
        {
            result->push_back(left->at(0));
            left->erase(left->begin());
        }
        else
        {
            result->push_back(right->at(0));
            right->erase(right->begin());
        }
    }
    while (left->size() > 0)
    {
        for (size_t i = 0; i < left->size(); i++)
            result->push_back(left->at(i));
        break;
    }
    while (right->size() > 0)
    {
        for (size_t i = 0; i < right->size(); i++)
            result->push_back(right->at(i));
        break;
    }
    delete left;
    delete right;
    return result;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static std::deque<int>*   deque_merge_sort(std::deque<int>* input, size_t threshold)
{
    if (input->size() <= threshold)
        return deque_insertion_sort(input);
    size_t mid = input->size() / 2;

    std::deque<int>*   left = new std::deque<int>;
    for (size_t i = 0; i < mid; i++)
        left->push_back(input->at(i));

    std::deque<int>*   right = new std::deque<int>;
    for (size_t i = mid; i < input->size(); i++)
        right->push_back(input->at(i));

    delete input;
    left = deque_merge_sort(left, threshold);
    right = deque_merge_sort(right, threshold);

    return deque_merge(left, right);
}

/* ************************************************************************** */

void    print_elapsed_time_in_usec(int count, std::string container, \
    struct timeval start, struct timeval end)
{
    std::cout << "Time to process a range of \t" << count \
        << " elements with std::" << container << "\t: " \
        << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) \
        << " us" << std::endl;
}

/* ************************************************************************** */

void    apply_insertion_merge_sort_algo(int argc, char *argv[])
{
    struct timeval  start, end;
    std::vector<int>*   input_v_array = new std::vector<int>;
    std::vector<int>*   output_v_array;
    std::deque<int>*    input_d_array = new std::deque<int>;
    std::deque<int>*    output_d_array;
    int             i = 0;
    std::string     input;  

    while (++i < argc)
    {
        input = argv[i];
        input_v_array->push_back(stoi(input));
    }
    print_vector_array("Before:\t", input_v_array);
    gettimeofday(&start, NULL);
    output_v_array = vector_merge_sort(input_v_array, 15);
    gettimeofday(&end, NULL);
    print_vector_array("After:\t", output_v_array);
    print_elapsed_time_in_usec(argc - 1, "vector", start, end);

    i = 0;
    while (++i < argc)
    {
        input = argv[i];
        input_d_array->push_back(stoi(input));
    }
    gettimeofday(&start, NULL);
    output_d_array = deque_merge_sort(input_d_array, 15);
    gettimeofday(&end, NULL);
    print_elapsed_time_in_usec(argc - 1, "deque", start, end);

    delete output_v_array;
    delete output_d_array;
}

