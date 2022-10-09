/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:53:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/03 18:24:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* ************************************************************************** */
/* **********************   Constructor/Destructor   ************************ */
/* ************************************************************************** */

HumanB::HumanB( std::string in_name )
{
	this->name = in_name;
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

HumanB::~HumanB( void )
{
	return ;
}

/* ************************************************************************** */
/* ******************************   Methods   ******************************* */
/* ************************************************************************** */

void	HumanB::attack( void ) const
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType();
	std::cout << std::endl;
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void	HumanB::setWeapon( Weapon &weapon )
{
	this->weapon = &weapon;
	return ;
}