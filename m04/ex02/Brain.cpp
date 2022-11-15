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

Brain::Brain(void)
{
	std::cout << "Brain Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Brain::Brain(Brain const &obj)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		setIdea(i, obj.getIdea(i));
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Brain &Brain::operator=(Brain const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "Brain Copy assignment operator called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		setIdea(i, obj.getIdea(i));
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

std::string Brain::getIdea(size_t index) const
{
	if (index < 100)
		return (m_ideas[index]);
	return ("");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Brain::setIdea(size_t index, std::string idea)
{
	if (index < 100)
		m_ideas[index] = idea;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Brain::printIdeas(void) const
{
	for (size_t i = 0; i < 100; i++)
		std::cout << i << ":\t" << m_ideas[i] << std::endl;
	return;
}
