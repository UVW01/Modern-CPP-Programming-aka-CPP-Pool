/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

ClapTrap::ClapTrap( void )
	: m_name("John Doe"), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;

	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ClapTrap::ClapTrap( std::string name )
	: m_name(name), m_hitPoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap Initialization constructor called" << std::endl;

	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ClapTrap::ClapTrap( ClapTrap const& obj )
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;

	m_name = obj.getName();
	m_hitPoints = obj.getHitPoints();
	m_energyPoints = obj.getEnergyPoints();
	m_attackDamage = obj.getAttackDamage();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void ClapTrap::operator = (ClapTrap const& obj)
{
	if (this == &obj)
		return ;
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;

	m_name = obj.getName();
	m_hitPoints = obj.getHitPoints();
	m_energyPoints = obj.getEnergyPoints();
	m_attackDamage = obj.getAttackDamage();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destructor called" << std::endl;

	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << m_name;
	if (m_energyPoints == 0 || m_hitPoints == 0)
	{
		std::cout << " doesn't have enough vitalities to attack " << target \
			<< "!" << std::endl;
		return ;
	}
	std::cout <<  " attacked " << target << ", causing "<< m_attackDamage \
		<< " points of damage!" << std::endl;
	m_energyPoints -= 1;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << m_name << " took " << amount <<  " of attack damage!" \
		<< std::endl;
	if (amount >= m_hitPoints)
		m_hitPoints = 0;
	else
		m_hitPoints -= amount;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << m_name;
	if (m_energyPoints == 0 || m_hitPoints == 0)
	{
		std::cout << " doesn't have enough vitalities to repair itself!" \
			<< std::endl;
		return ;
	}
	std::cout <<  " repaired itself with " << amount << " of health!" \
		<< std::endl;
	m_hitPoints += amount;
	m_energyPoints -= 1;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* - - - - - - - - - - - - - - - -  GETTERS  - - - - - - - - - - - - - - - - -*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

std::string		ClapTrap::getName( void ) const
{
	return (m_name);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

unsigned int	ClapTrap::getHitPoints( void ) const
{
	return (m_hitPoints);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	return (m_energyPoints);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return (m_attackDamage);
}
