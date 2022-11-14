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

Brain::Brain( Brain const &obj )
{
	*this = obj;
	std::cout << "Brain Copy constructor called" << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Brain::operator = (Brain const &obj)
{
	const std::string*	obj_ideas = obj.getIdeas();

	std::copy(obj_ideas, obj_ideas + 100, m_ideas);
	std::cout << "Brain Copy assignment operator called" << std::endl;
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
	return (m_ideas);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Brain::setIdeas( size_t index, std::string idea )
{
	if ( index < 100 )
		m_ideas[index] = idea;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Brain::printIdeas( void ) const
{
	for (size_t i = 0; i < 100; i++)
		std::cout << i << ":\t" << m_ideas[i] << std::endl;
	return ;
}
