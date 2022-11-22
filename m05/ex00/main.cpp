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

/* ************************************************************************** */

static void bureaucratTest(void)
{
	try
	{
		Bureaucrat naimi("Naimi", 156);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat naimi("Naimi", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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

int	main(void)
{
	std::cout << "\n-------------------------------------------\n" << std::endl;
	bureaucratTest();
	std::cout << "\n-------------------------------------------\n" << std::endl;
	return (0);
}
