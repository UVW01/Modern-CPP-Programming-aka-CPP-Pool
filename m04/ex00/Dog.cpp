/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Dog::Dog( void ): Animal( "Dog" )
{
	std::cout << "Dog Default constructor called" << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Dog::Dog( Dog const& obj )
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Dog::operator = (Dog const& obj)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	this->type = obj.getType();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void	Dog::makeSound( void ) const
{
	std::cout << "* woof woof *" << std::endl;
	return ;
}


