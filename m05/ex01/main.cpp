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

/* ************************************************************************** */

static void bureaucratTest(void)
{
	Bureaucrat	mohamed("Mohamed", 1);
	Bureaucrat	amine("Amine", 150);

	std::cout << mohamed << amine << std::endl;
	try
	{
		mohamed.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		amine.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	mohamed.decrementGrade();
	amine.incrementGrade();
	std::cout << mohamed << amine << std::endl;
}

/* ************************************************************************** */

static void formTest(void)
{
	Bureaucrat				mohamed("Mohamed", 1);
	Bureaucrat				amine("Amine", 150);
	Form					form("Garden", 23, 40);

	std::cout << mohamed << amine << form << std::endl;
	try
	{
		amine.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	mohamed.signForm(form);
	std::cout << form << std::endl;
}

/* ************************************************************************** */

int	main(void)
{
	std::cout << "\n-------------------------------------------\n" << std::endl;
	bureaucratTest();
	std::cout << "\n-------------------------------------------\n" << std::endl;
	formTest();
	std::cout << "\n-------------------------------------------\n" << std::endl;
	return (0);
}
