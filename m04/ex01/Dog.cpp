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

Dog::Dog(void)
	: Animal("Dog"), m_brain(NULL)
{
	std::cout << "Dog Default constructor called" << std::endl;
	m_brain = new Brain();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Dog::Dog(Dog const &obj)
	: Animal(obj), m_brain(NULL)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	m_brain = new Brain();
	for (size_t i = 0; i < 100; i++)
		setIdea(i, obj.getIdea(i));
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Dog &Dog::operator=(Dog const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "Dog Copy assignment operator called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		setIdea(i, obj.getIdea(i));
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Dog::~Dog(void)
{
	delete (m_brain);
	std::cout << "Dog Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

const Brain &Dog::getBrain(void) const
{
	return (*m_brain);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

std::string Dog::getIdea(size_t index) const
{
	return (m_brain->getIdea(index));
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Dog::setIdea(size_t index, std::string idea)
{
	m_brain->setIdea(index, idea);
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Dog::printIdeas(void) const
{
	m_brain->printIdeas();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Dog::makeSound(void) const
{
	std::cout << "* meoow meoow *" << std::endl;
	return;
}
