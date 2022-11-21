/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 22:27:20 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Form::Form(void)
	: name_("Form"), is_signed_(false), sign_grade_(150), exec_grade_(150)
{
	std::cout << "Form Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Form::Form(std::string name, int sign_grade, int exec_grade)
	: name_(name), is_signed_(false)
	, sign_grade_(sign_grade), exec_grade_(exec_grade)
{
	std::cout << "Form Initialization constructor called" << std::endl;
	if (sign_grade_ > 150 || exec_grade_ > 150)
		throw Form::GradeTooLowException();
	else if (sign_grade_ < 1 || exec_grade_ < 1)
		throw Form::GradeTooHighException();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Form::Form(Form const &obj)
	: name_(obj.name_), is_signed_(obj.is_signed_)
	, sign_grade_(obj.sign_grade_), exec_grade_(obj.exec_grade_)
{
	std::cout << "Form Copy constructor called" << std::endl;
	if (sign_grade_ > 150 || exec_grade_ > 150)
		throw Form::GradeTooLowException();
	else if (sign_grade_ < 1 || exec_grade_ < 1)
		throw Form::GradeTooHighException();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Form &Form::operator=(Form const &obj)
{
	if (this != &obj)
	{
		std::cout << "Form Copy assignment operator called" << std::endl;
		is_signed_ = obj.getSignStatus();
		if (sign_grade_ > 150 || exec_grade_ > 150)
			throw Form::GradeTooLowException();
		else if (sign_grade_ < 1 || exec_grade_ < 1)
			throw Form::GradeTooHighException();
	}
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Form::~Form(void)
{
	std::cout << "Form Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::string	Form::getName(void) const
{
	return (name_);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

bool	Form::getSignStatus(void) const
{
	return (is_signed_);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

int	Form::getSignGrade(void) const
{
	return (sign_grade_);
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

int	Form::getExecGrade(void) const
{
	return (exec_grade_);
}

/* -------------------------------------------------------------------------- */

void	Form::beSigned(Bureaucrat const& obj)
{
	int bureaucrat_grade = obj.getGrade();
	if (bureaucrat_grade > sign_grade_)
		throw Form::GradeTooLowException();
	is_signed_ = true;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Form::checkFormForExec(Bureaucrat const &executor) const
{
	if (is_signed_ == false)
		throw Form::FormNotYetSigned();
	else if (executor.getGrade() > exec_grade_)
		throw Form::GradeTooLowException();
	return;
}

/* -------------------------------------------------------------------------- */

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too High!");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too Low!");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

const char *Form::FormNotYetSigned::what() const throw()
{
	return ("The Form is not yet Signed!");
}

/* ************************************************************************** */
/* *****************************  FUNCTIONS  ******************************** */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &output_stream, Form const &obj)
{
	bool	form_is_signed = obj.getSignStatus();

	output_stream << obj.getName();
	output_stream << (form_is_signed ? " is signed" : " is not signed");
	output_stream << ", sign_grade " << obj.getSignGrade();
	output_stream << ", exec_grade " << obj.getExecGrade() << std::endl;
	return (output_stream);
}
