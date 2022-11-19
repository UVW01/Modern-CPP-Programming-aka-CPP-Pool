/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:16:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 21:22:46 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP_
#define BUREAUCRAT_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

class Form;

class Bureaucrat
{
	private:
		const std::string	name_;
		int					grade_;

	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &);
		Bureaucrat(std::string, int);
		Bureaucrat &operator=(Bureaucrat const &);
		~Bureaucrat(void);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		std::string		getName(void) const;
		uint			getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form &);
};

/* ************************************************************************** */
/* ****************************   PROTOTYPES   ****************************** */
/* ************************************************************************** */

std::ostream &operator<<(std::ostream &out, Bureaucrat const &c);

#endif
