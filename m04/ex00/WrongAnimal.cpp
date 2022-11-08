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

WrongAnimal::WrongAnimal( void ): type( "N/A" )
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongAnimal::WrongAnimal( std::string input_type ): type( input_type )
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongAnimal::WrongAnimal( WrongAnimal const& obj )
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void WrongAnimal::operator = (WrongAnimal const& obj)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	this->type = obj.getType();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	WrongAnimal::setType( std::string input_type )
{
	this->type = input_type;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "* #$@!%#$@!%#$@!%#$@!%#$@!%#$@!% *" << std::endl;
	return ;
}


