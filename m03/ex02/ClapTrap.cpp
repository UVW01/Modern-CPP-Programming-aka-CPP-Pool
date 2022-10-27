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

ClapTrap::ClapTrap( void ): name("UNKNOWN"), hitPoints(10), energyPoints(10), \
	attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ClapTrap::ClapTrap( std::string name ): name(name), hitPoints(10), \
	energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Initialization constructor called" << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ClapTrap::ClapTrap( ClapTrap const& obj )
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void ClapTrap::operator = (ClapTrap const& obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	name = obj.getName();
	hitPoints = obj.getHitPoints();
	energyPoints = obj.getEnergyPoints();
	attackDamage = obj.getAttackDamage();
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

std::string		ClapTrap::getName( void ) const
{
	return (name);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

unsigned int	ClapTrap::getHitPoints( void ) const
{
	return (hitPoints);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

unsigned int	ClapTrap::getEnergyPoints( void ) const
{
	return (energyPoints);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

unsigned int	ClapTrap::getAttackDamage( void ) const
{
	return (attackDamage);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap" << name;
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << " doesn't have enough vitalities to attack "<< target;
		std::cout << "!" << std::endl;
		return ;
	}
	std::cout <<  "attacks " << target << ", causing ";
	std::cout << attackDamage << " points of damage!" << std::endl;
	energyPoints -= 1;
	return ;
}


void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap" << name << "took " << amount;
	std::cout << " of attack damage!" << std::endl;
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	return ;
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap" << name;
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << " doesn't have enough vitalities to repair itself!";
		std::cout << std::endl;
		return ;
	}
	std::cout <<  "repaired itself with " << amount << "of health!";
	std::cout << std::endl;
	hitPoints += amount;
	energyPoints -= 1;
	return ;
}

