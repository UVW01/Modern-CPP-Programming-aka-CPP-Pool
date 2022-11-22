/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 22:27:20 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Intern::Intern(void)
{
	std::cout << "Intern Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Intern::Intern(Intern const &obj)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	(void)obj;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Intern &Intern::operator=(Intern const &obj)
{
	if (this != &obj)
	{
		std::cout << "Intern Copy assignment operator called" << std::endl;	
	}
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

Form	*Intern::makeForm(std::string form_name, std::string form_target)
{
	Form			*output_form = NULL;
	int				index = 0;
	std::string		form_names[4] = {
		"robotomy request", "shrubbery creation",
		"presidential pardon", "dummy"
	};

	while (index < 4 && form_name.compare(form_names[index]))
		index++;
	switch (index)
	{
		case 0:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			output_form = new RobotomyRequestForm(form_target);
			break;
		case 1:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			output_form = new ShrubberyCreationForm(form_target);
			break;
		case 2:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			output_form = new PresidentialPardonForm(form_target);
			break;
		default:
			std::cerr << "No matching form found!" << std::endl;
			break;
	}
	return (output_form);
}
