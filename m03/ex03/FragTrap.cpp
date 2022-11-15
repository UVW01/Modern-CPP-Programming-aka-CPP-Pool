/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;

	m_name = "John Doe";
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

FragTrap::FragTrap(std::string input_name) : ClapTrap(input_name)
{
	std::cout << "FragTrap Initialization constructor called" << std::endl;

	m_name = input_name;
	m_hitPoints = 100;
	m_energyPoints = 100;
	m_attackDamage = 30;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

FragTrap::FragTrap(FragTrap const &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;

	m_name = obj.getName();
	m_hitPoints = obj.getHitPoints();
	m_energyPoints = obj.getEnergyPoints();
	m_attackDamage = obj.getAttackDamage();
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

FragTrap &FragTrap::operator=(FragTrap const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "FragTrap Copy assignment operator called" << std::endl;

	m_name = obj.getName();
	m_hitPoints = obj.getHitPoints();
	m_energyPoints = obj.getEnergyPoints();
	m_attackDamage = obj.getAttackDamage();
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;

	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void FragTrap::highFivesGuys(void)
{
	std::cout << m_name << " wants to high-five you!!" << std::endl;

	return;
}
