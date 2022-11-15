/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

WrongCat::WrongCat(void)
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongCat::WrongCat(WrongCat const &obj)
	: WrongAnimal(obj)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	m_type = obj.getType();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongCat &WrongCat::operator=(WrongCat const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	m_type = obj.getType();
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void WrongCat::makeSound(void) const
{
	std::cout << "* friw kriw ... friw kriw *" << std::endl;
	return;
}
