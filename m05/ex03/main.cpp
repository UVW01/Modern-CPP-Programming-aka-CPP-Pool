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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

static void shrubberyCreationTest(void)
{
	Bureaucrat				mohamed("Mohamed", 1);
	ShrubberyCreationForm	s_form("Garden");

	std::cout << mohamed << s_form << std::endl;
	mohamed.executeForm(s_form);
	mohamed.signForm(s_form);
	mohamed.executeForm(s_form);
}

/* ************************************************************************** */

static void robotomyRequestTest(void)
{
	Bureaucrat				mohamed("Amine", 1);
	RobotomyRequestForm		r_form("Terminator");

	std::cout << mohamed << r_form << std::endl;
	mohamed.executeForm(r_form);
	mohamed.signForm(r_form);
	mohamed.executeForm(r_form);
}

/* ************************************************************************** */

static void presidentialPardonTest(void)
{
	Bureaucrat				mohamed("Naimi", 1);
	PresidentialPardonForm	p_form("Cunt");

	std::cout << mohamed << p_form << std::endl;
	mohamed.executeForm(p_form);
	mohamed.signForm(p_form);
	mohamed.executeForm(p_form);
}

/* ************************************************************************** */

static void internTest(void)
{
	Form		*form;
	Intern		intern;
	std::cout << std::endl << std::endl << std::endl;
	form = intern.makeForm("shrubbery creation", "Bonsai");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = intern.makeForm("robotomy request", "Terminator");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = intern.makeForm("presidential pardon", "Trump");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = intern.makeForm("green card", "Trump");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	return ;
}

/* ************************************************************************** */

int	main(void)
{
	bureaucratTest();
	std::cout << "\n-------------------------------------------\n" << std::endl;
	shrubberyCreationTest();
	std::cout << "\n-------------------------------------------\n" << std::endl;
	robotomyRequestTest();
	std::cout << "\n-------------------------------------------\n" << std::endl;
	presidentialPardonTest();
	std::cout << "\n-------------------------------------------\n" << std::endl;
	internTest();
	return (0);
}
