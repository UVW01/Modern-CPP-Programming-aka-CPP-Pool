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

Cat::Cat(void)
	: Animal("Cat"), m_brain(NULL)
{
	std::cout << "Cat Default constructor called" << std::endl;
	m_brain = new Brain();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Cat::Cat(Cat const &obj)
	: Animal(obj), m_brain(NULL)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	m_brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		setIdea(i, obj.getIdea(i));
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Cat &Cat::operator=(Cat const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "Cat Copy assignment operator called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		setIdea(i, obj.getIdea(i));
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Cat::~Cat(void)
{
	delete (m_brain);
	std::cout << "Cat Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

const Brain &Cat::getBrain(void) const
{
	return (*m_brain);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

std::string Cat::getIdea(size_t index) const
{
	return (m_brain->getIdea(index));
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Cat::setIdea(size_t index, std::string idea)
{
	m_brain->setIdea(index, idea);
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Cat::printIdeas(void) const
{
	m_brain->printIdeas();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Cat::makeSound(void) const
{
	std::cout << "* meoow meoow *" << std::endl;
	return;
}
