/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void)
	: ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;

	m_name = "John Doe";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
	ClapTrap::m_name = m_name + "_clap_name";
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

DiamondTrap::DiamondTrap(std::string input_name)
	: ClapTrap(input_name + "_clap_name"), FragTrap(input_name), ScavTrap(input_name)
{
	std::cout << "DiamondTrap Initialization constructor called" << std::endl;

	m_name = input_name;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 30;
	ClapTrap::m_name = m_name + "_clap_name";
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

DiamondTrap::DiamondTrap(DiamondTrap const &obj)
	: ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;

	m_name = obj.getDiamondName();
	m_hitPoints = obj.getHitPoints();
	m_energyPoints = obj.getEnergyPoints();
	m_attackDamage = obj.getAttackDamage();
	ClapTrap::m_name = m_name + "_clap_name";
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;

	m_name = obj.getDiamondName();
	m_hitPoints = obj.getHitPoints();
	m_energyPoints = obj.getEnergyPoints();
	m_attackDamage = obj.getAttackDamage();
	ClapTrap::m_name = m_name + "_clap_name";
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;

	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void DiamondTrap::whoAmI(void)
{
	std::cout << "D.T. Name: " << m_name << std::endl;
	std::cout << "C.T. Name: " << ClapTrap::m_name << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* - - - - - - - - - - - - - - - -  GETTERS  - - - - - - - - - - - - - - - - -*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

std::string DiamondTrap::getDiamondName(void) const
{
	return (m_name);
}
