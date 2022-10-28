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
	name = "UNKNOWN";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ScavTrap::ScavTrap( std::string input_name ): ClapTrap( input_name )
{
	std::cout << "ScavTrap Initialization constructor called" << std::endl;
	name = input_name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

ScavTrap::ScavTrap( ScavTrap const& obj ): ClapTrap( obj )
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void ScavTrap::operator = (ScavTrap const& obj)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	name = obj.getName();
	hitPoints = obj.getHitPoints();
	energyPoints = obj.getEnergyPoints();
	attackDamage = obj.getAttackDamage();
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
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
	return ;
}
