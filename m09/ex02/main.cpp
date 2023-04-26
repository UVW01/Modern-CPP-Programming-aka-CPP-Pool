/* ************************************************************************** */
/* ******************************  LIBRARIES  ******************************* */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/* *********************************  MAIN  ********************************* */
/* ************************************************************************** */

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return EXIT_FAILURE;
    }
    std::stringstream   ss(argv[1]);
    if (!string_has_only_positive_integers(argv[1]))
    {
        std::cout << "Error" << std::endl;
        return EXIT_FAILURE;
    }
    try
    {
        apply_insertion_merge_sort_algo(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cout << "Internal Error" << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
