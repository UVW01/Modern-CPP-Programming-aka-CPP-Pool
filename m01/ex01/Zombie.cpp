/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:53:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/03 18:24:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* ************************************************************************** */
/* **********************   Constructor/Destructor   ************************ */
/* ************************************************************************** */

Zombie::Zombie( std::string input_name )
{
	this->name = input_name;
	std::cerr << this->name << " has risen from the ground" << std::endl;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Zombie::~Zombie( void )
{
	std::cerr << this->name << " has been exterminated" << std::endl;
}

/* ************************************************************************** */
/* ******************************   Methods   ******************************* */
/* ************************************************************************** */

void	Zombie::set_name( std::string input_name )
{
	this->name = input_name;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

std::string	Zombie::get_name( void )
{
	return (this->name);
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
