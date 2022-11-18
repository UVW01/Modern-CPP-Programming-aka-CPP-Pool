/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:16:34 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 21:21:55 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Bureaucrat::Bureaucrat(void)
	: name_("Bureaucrat"), grade_(150)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	return;
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name_(name), grade_(grade)
{
	if (grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Bureaucrat::Bureaucrat(Bureaucrat const &obj)
	: name_(obj.name_), grade_(obj.grade_)
{
	if (grade_ > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade_ < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
	{
		std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
		grade_ = obj.getGrade();
		if (grade_ > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade_ < 1)
			throw Bureaucrat::GradeTooHighException();
	}
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::string	Bureaucrat::getName(void) const
{
	return (name_);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

uint	Bureaucrat::getGrade(void) const
{
	return (grade_);
}
	
/* -------------------------------------------------------------------------- */

void	Bureaucrat::incrementGrade(void)
{
	grade_ -= 1;
	if (grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Bureaucrat::decrementGrade(void)
{
	grade_ += 1;
	if (grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	return;
}

/* -------------------------------------------------------------------------- */

const char *Bureaucrat::GradeTooHighException::what() const
{
	return ("The grade is too High!");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

const char *Bureaucrat::GradeTooLowException::what() const
{
	return ("The grade is too Low!");
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &output_stream, Bureaucrat const &obj)
{
	output_stream << obj.getName() << ", bureaucrat grade " << obj.getGrade()
		<< "." << std::endl;
	return (output_stream);
}
