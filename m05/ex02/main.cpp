/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:16:36 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 21:22:24 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#define GREEN "\e[32m"
#define RESET "\e[m"


void test_low()
{
    std::cout << GREEN << "TESTING WITH LOW GRADE" << RESET <<std::endl;

    try{
        Form form("Man", 51, 10);
    }
    catch(std::exception& excp){
        std::cout << excp.what() << std::endl;
    }
}

void test_high()
{
    std::cout << GREEN << "TESTING WITH HIGH GRADE" << RESET <<std::endl;

    try{
        Form form ("Woman", 1, 20);
    }
    catch(std::exception& excp){
        std::cout << excp.what() << std::endl;
    }
}

void test_confirm_sign()
{
    std::cout << GREEN << "TESTING INCREMENTATION GRADE" << RESET <<std::endl;
    try {
        Bureaucrat me("me", 1);
        Form boy("bot", 4, 2);
        boy.beSigned(me);
    }
    catch (std::exception& excp){
        std::cout << excp.what() << std::endl;
    }
}

int main()
{
    test_low();
    test_high();
    test_confirm_sign();

    return (0);
}
