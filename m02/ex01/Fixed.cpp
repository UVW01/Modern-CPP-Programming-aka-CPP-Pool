/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Fixed::Fixed( void ): fp_(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed::Fixed( Fixed const& ref )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed::Fixed( int const value )
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits( value << fract_bits_no_ );
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed::Fixed( float const value )
{
	std::cout << "Float constructor called" << std::endl;
	int32_t fix = (int32_t)roundf(value * (1 << fract_bits_no_));
	setRawBits( fix );
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void Fixed::operator=(Fixed const& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fp_ = obj.getRawBits();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

int		Fixed::getRawBits( void ) const
{
	return (fp_);
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

void	Fixed::setRawBits( int const raw )
{
	fp_ = raw;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

float	Fixed::toFloat( void ) const
{
	int32_t	fix = getRawBits();

	return ((float)fix / (float)(1 << fract_bits_no_));
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

int		Fixed::toInt( void ) const
{
	int32_t	fix = getRawBits();

	return ((int)fix / (int)(1 << fract_bits_no_));
}

/* ************************************************************************** */
/* *****************************  FUNCTIONS  ******************************** */
/* ************************************************************************** */

std::ostream& operator << (std::ostream &out, Fixed const &c)
{
    out << c.toFloat();
    return out;
}
