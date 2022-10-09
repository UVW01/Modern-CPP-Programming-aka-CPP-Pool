/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Harl::Harl( void )
{
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Harl::~Harl( void )
{
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl << std::endl;
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!" << std::endl << std::endl;
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << std::endl;
	std::cout << "I’ve been coming for years whereas you started working ";
	std::cout << "here since last month." << std::endl << std::endl;
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

static void	nonsense( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]";
	std::cout << std::endl << std::endl;
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void	Harl::complain( std::string level )
{
	std::string	f_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*f_ptr[4])( void ) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};
	size_t		f_index = -1;

	for ( size_t i = 0; i < 4; i++ )
	{
		if ( f_str[i].compare(level) == 0 )
		{
			f_index = i;
			break ;
		}
	}
	switch ( f_index )
	{
		case 0:
			(this->*f_ptr[0])();
		case 1:
			(this->*f_ptr[1])();
		case 2:
			(this->*f_ptr[2])();
		case 3:
			(this->*f_ptr[3])(); break ;
		default:
			nonsense();
	}
	return ;
}
