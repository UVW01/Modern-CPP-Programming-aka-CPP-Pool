/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/17 00:13:37 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIAL_PARDON_FORM_HPP_
#define PRESIDENTIAL_PARDON_FORM_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

class PresidentialPardonForm: public Form
{
	private:
		std::string		target_;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(PresidentialPardonForm const &);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &);
		~PresidentialPardonForm(void);

		std::string	getTarget(void) const;
		void		execute(Bureaucrat const & executor) const;
};

/* ************************************************************************** */
/* ****************************   PROTOTYPES   ****************************** */
/* ************************************************************************** */

#endif
