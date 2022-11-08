/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Cat::Cat( void ): Animal( "Cat" )
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->brain = new Brain();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Cat::Cat( Cat const& obj )
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Cat::operator = (Cat const& obj)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	this->type = obj.getType();
	*brain = obj.getBrain();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called" << std::endl;
	delete (this->brain);
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

const Brain&	Cat::getBrain( void ) const
{
	return (*brain);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Cat::makeSound( void ) const
{
	std::cout << "* meoow meoow *" << std::endl;
	return ;
}
