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

FragTrap::FragTrap( void ): ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	name = "UNKNOWN";
	hitPoints = 100;
	//energyPoints = 100;
	attackDamage = 30;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

FragTrap::FragTrap( std::string input_name ): ClapTrap( input_name )
{
	std::cout << "FragTrap Initialization constructor called" << std::endl;
	name = input_name;
	hitPoints = 100;
	//energyPoints = 100;
	attackDamage = 30;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

FragTrap::FragTrap( FragTrap const& obj ): ClapTrap( obj )
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void FragTrap::operator = (FragTrap const& obj)
{
	operator=(static_cast<ClapTrap const&>(obj));
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	name = obj.getName();
	hitPoints = obj.getHitPoints();
	//energyPoints = obj.getEnergyPoints();
	attackDamage = obj.getAttackDamage();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void	FragTrap::highFivesGuys( void )
{
	std::cout << name << " wants to high-five you!!" << std::endl;
	return ;
}
