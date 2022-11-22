/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 22:27:20 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("Robotomy Request", 72, 45), target_("Company")
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("Robotomy Request", 72, 45), target_(target)
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj)
	: Form(obj), target_(obj.getTarget())
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	if (this != &obj)
	{
		Form::operator=(obj);
		std::cout << "RobotomyRequestForm Copy assignment operator called" \
			<< std::endl;
		target_ = obj.getTarget();
	}
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (target_);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkFormForExec(executor);
	struct timeval	time;

	gettimeofday(&time, NULL);
	srand((time.tv_sec * 1000000) + time.tv_usec);
	std::cout << target_;
	if (rand() % 2)
		std::cout << " has been robotomized successfully!";
	else
		std::cout << "'s robotomy has failed!";
	std::cout << std::endl;
	return ;
}
