/* ************************************************************************** */
/* ******************************  LIBRARIES  ******************************* */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */
/* *******************************  FUNCTIONS  ****************************** */
/* ************************************************************************** */

static bool is_number(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false)
            return false;
    }
    return true;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

static bool is_math_operator(std::string str) {
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return true;
    return false;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **/

int input_to_array(std::string input) {
    int i = 0;
    std::stringstream ss(input);
    std::string token;
    std::stack<int> stack;
    int a, b;

    while (std::getline(ss, token, ' ')) {
        if (is_number(token))
            stack.push(std::stoi(token));
        else if (is_math_operator(token)) {
            if (stack.size() < 2)
                throw std::invalid_argument("Error");
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            if (token == "+")
                stack.push(b + a);
            else if (token == "-")
                stack.push(b - a);
            else if (token == "*")
                stack.push(b * a);
            else if (token == "/")
                stack.push(b / a);
        }
        else
            throw std::invalid_argument("Error");
        i++;
    }
    std::cout << stack.top() << std::endl;
    return EXIT_SUCCESS;
}


/* ************************************************************************** */




