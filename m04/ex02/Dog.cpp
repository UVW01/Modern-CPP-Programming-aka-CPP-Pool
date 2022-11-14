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

Dog::Dog( void ): Animal( "Dog" ), m_brain(NULL)
{
	std::cout << "Dog Default constructor called" << std::endl;
	m_brain = new Brain();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Dog::Dog( Dog const& obj ): Animal( obj ), m_brain(NULL)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void Dog::operator = (Dog const& obj)
{
	operator=(static_cast<const Animal&>(obj));
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (m_brain == NULL)
		m_brain = new Brain();
	*(m_brain) = obj.getBrain();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Dog::~Dog( void )
{
	delete (m_brain);
	std::cout << "Dog Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

const Brain&	Dog::getBrain( void ) const
{
	return (*m_brain);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

const std::string*	Dog::getIdeas( void ) const
{
	return (m_brain->getIdeas());
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Dog::setIdeas( size_t index, std::string idea )
{
	m_brain->setIdeas(index, idea);
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Dog::printIdeas( void ) const
{
	m_brain->printIdeas();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Dog::makeSound( void ) const
{
	std::cout << "* woof woof *" << std::endl;
	return ;
}
