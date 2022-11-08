/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Brain::Brain( void )
{
	std::cout << "Brain Default constructor called" << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Brain::Brain( Brain const& obj )
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Brain::operator = (Brain const& obj)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	const std::string *ideas = obj.getIdeas();
	// for (size_t i = 0; i < 100; i++)
	// 	this->ideas[i] = ideas[i];
	std::copy(ideas, ideas + 100, this->ideas);
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

const std::string*	Brain::getIdeas( void ) const
{
	return (this->ideas);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Brain::setIdeas( size_t index, std::string idea )
{
	if ( index < 100 )
		ideas[index] = idea;
	return ;
}
