/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Animal::Animal(void)
	: m_type("N/A")
{
	std::cout << "Animal Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Animal::Animal(std::string input_type)
	: m_type(input_type)
{
	std::cout << "Animal Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Animal::Animal(Animal const &obj)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	m_type = obj.getType();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Animal &Animal::operator=(Animal const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "Animal Copy assignment operator called" << std::endl;
	m_type = obj.getType();
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::string Animal::getType(void) const
{
	return (m_type);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Animal::setType(std::string input_type)
{
	m_type = input_type;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Animal::makeSound(void) const
{
	std::cout << "* UNIDENTIFIABLE NOISES *" << std::endl;
	return;
}
