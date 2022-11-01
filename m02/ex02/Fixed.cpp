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
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Fixed::Fixed( Fixed const& ref )
{
	*this = ref;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Fixed::Fixed( int const value )
{
	setRawBits( value << fract_bits_no_ );
	return ;
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed::Fixed( float const value )
{
	int32_t fix = (int32_t)roundf(value * (1 << fract_bits_no_));
	setRawBits( fix );
	return ;
}

/* -------------------------------------------------------------------------- */

Fixed::~Fixed( void )
{
	return ;
}

/* ************************************************************************** */
/* **********************   OPERATOR OVERLOADING    ************************* */
/* ************************************************************************** */

void	Fixed::operator = ( Fixed const& obj )
{
	fp_ = obj.getRawBits();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

bool	Fixed::operator > ( Fixed const& obj )
{
	return (fp_ > obj.getRawBits());
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

bool	Fixed::operator < ( Fixed const& obj )
{
	return (fp_ < obj.getRawBits());
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

bool	Fixed::operator >= ( Fixed const& obj )
{
	return (fp_ >= obj.getRawBits());
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

bool	Fixed::operator <= ( Fixed const& obj )
{
	return (fp_ <= obj.getRawBits());
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

bool	Fixed::operator == ( Fixed const& obj )
{
	return (fp_ == obj.getRawBits());
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

bool	Fixed::operator != ( Fixed const& obj )
{
	return (fp_ != obj.getRawBits());
}

/* -------------------------------------------------------------------------- */

Fixed	Fixed::operator + ( Fixed const& obj )
{
	int	temp = obj.getRawBits();
	return (fp_ + temp);
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed	Fixed::operator - ( Fixed const& obj )
{
	int	temp = obj.getRawBits();
	return (fp_ - temp);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Fixed	Fixed::operator * ( Fixed const& obj )
{
	float	result = toFloat() * obj.toFloat();
	Fixed	temp(result);
	return (temp);
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed	Fixed::operator / ( Fixed const& obj )
{
	float	result = toFloat() / obj.toFloat();
	Fixed	temp(result);
	return (temp);
}

/* -------------------------------------------------------------------------- */

Fixed&	Fixed::operator ++ ( void )
{
	fp_ += 1;
	return (*this);
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed	Fixed::operator ++ ( int )
{
	Fixed	temp = (*this);

	++(*this);
	return (temp);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Fixed&	Fixed::operator -- ( void )
{
	fp_ -= 1;
	return (*this);
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed	Fixed::operator -- ( int )
{
	Fixed	temp = (*this);

	--(*this);
	return (temp);
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
	int32_t	fix = this->getRawBits();

	return ((float)fix / (float)(1 << fract_bits_no_));
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

int		Fixed::toInt( void ) const
{
	int32_t	fix = getRawBits();

	return ((int)fix / (int)(1 << fract_bits_no_));
}

/* -------------------------------------------------------------------------- */

Fixed&	Fixed::min( Fixed& obj1, Fixed& obj2 )
{
	return (obj1.toFloat() < obj2.toFloat() ?  obj1 : obj2);
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed&	Fixed::max( Fixed& obj1, Fixed& obj2 )
{
	return (obj1.toFloat() > obj2.toFloat() ? obj1 : obj2);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Fixed&	Fixed::min( Fixed const& obj1, Fixed const& obj2 )
{
	float	f1 = obj1.toFloat();
	float	f2 = obj2.toFloat();
	return (f1 < f2 ? const_cast <Fixed &>(obj1) : const_cast <Fixed &>(obj2));
}

/* -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  */

Fixed&	Fixed::max( Fixed const& obj1, Fixed const& obj2 )
{
	float	f1 = obj1.toFloat();
	float	f2 = obj2.toFloat();
	return (f1 > f2 ? const_cast <Fixed &>(obj1) : const_cast <Fixed &>(obj2));
}

/* ************************************************************************** */
/* *****************************  FUNCTIONS  ******************************** */
/* ************************************************************************** */

std::ostream& operator << ( std::ostream &out, Fixed const &obj )
{
    out << obj.toFloat();
    return (out);
}
