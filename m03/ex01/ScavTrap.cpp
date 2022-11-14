/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

ScavTrap::ScavTrap( void ): ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;

	m_name = "John Doe";
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ScavTrap::ScavTrap( std::string input_name ): ClapTrap( input_name )
{
	std::cout << "ScavTrap Initialization constructor called" << std::endl;

	m_name = input_name;
	m_hitPoints = 100;
	m_energyPoints = 50;
	m_attackDamage = 20;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ScavTrap::ScavTrap( ScavTrap const& obj ): ClapTrap( obj )
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;

	m_name = obj.getName();
	m_hitPoints = obj.getHitPoints();
	m_energyPoints = obj.getEnergyPoints();
	m_attackDamage = obj.getAttackDamage();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void ScavTrap::operator = (ScavTrap const& obj)
{
	ClapTrap::operator=(obj);

	if (this == &obj)
		return ;
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;

	m_name = obj.getName();
	m_hitPoints = obj.getHitPoints();
	m_energyPoints = obj.getEnergyPoints();
	m_attackDamage = obj.getAttackDamage();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap Destructor called" << std::endl;

	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;

	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	ScavTrap::attack( const std::string& target )
{
	std::cout << "ScavpTrap " << m_name;
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
