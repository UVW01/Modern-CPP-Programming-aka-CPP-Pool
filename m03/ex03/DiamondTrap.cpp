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

DiamondTrap::DiamondTrap( void ): FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	name = "UNKNOWN";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	ClapTrap::name = name + "_clap_name";
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

DiamondTrap::DiamondTrap( std::string input_name ): FragTrap( input_name ), \
	ScavTrap( input_name )
{
	std::cout << "DiamondTrap Initialization constructor called" << std::endl;
	name = input_name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;
	ClapTrap::name = name + "_clap_name";
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

DiamondTrap::DiamondTrap( DiamondTrap const& obj ): FragTrap( obj ), \
	ScavTrap( obj )
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	DiamondTrap::operator = (DiamondTrap const& obj)
{
	operator=(static_cast<FragTrap const&>(obj));
	operator=(static_cast<ScavTrap const&>(obj));
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	DiamondTrap::name = obj.getName();
	hitPoints = obj.getHitPoints();
	energyPoints = obj.getEnergyPoints();
	attackDamage = obj.getAttackDamage();
	ClapTrap::name = DiamondTrap::name + "_clap_name";
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void	DiamondTrap::whoAmI( void )
{
	std::cout << "D.T. Name: " << name << std::endl;
	std::cout << "C.T. Name: " << ClapTrap::name << std::endl;
	return ;
}
