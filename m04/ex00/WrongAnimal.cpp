/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void)
	: m_type("N/A")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongAnimal::WrongAnimal(std::string input_type)
	: m_type(input_type)
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongAnimal::WrongAnimal(WrongAnimal const &obj)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	m_type = obj.getType();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	m_type = obj.getType();
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::string WrongAnimal::getType(void) const
{
	return (m_type);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void WrongAnimal::setType(std::string input_type)
{
	m_type = input_type;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void WrongAnimal::makeSound(void) const
{
	std::cout << "* #$@_!#_$%$@!_%$@_%#_$@_!#$@_!% *" << std::endl;
	return;
}
