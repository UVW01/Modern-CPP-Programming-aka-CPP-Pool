/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */


Point::Point( void ): x_(0), y_(0)
{
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Point::Point( Point const& ref )
{
	*this = ref;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Point::Point( float const x, float const y ): x_(x), y_(y)
{
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Point::operator = ( Point const& obj )
{
	Fixed& myX = const_cast<Fixed&>(x_);
	Fixed& myY = const_cast<Fixed&>(y_);
	myX = obj.getXPoint();
	myY = obj.getYPoint();
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Point::~Point( void )
{
	return ;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

Fixed&	Point::getXPoint( void ) const
{
	return (const_cast <Fixed&>(x_));
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Fixed&	Point::getYPoint( void ) const
{
	return (const_cast <Fixed&>(y_));
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

float	Point::getFloatXPoint( void ) const
{
	return (x_.toFloat());
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

float	Point::getFloatYPoint( void ) const
{
	return (y_.toFloat());
}

/* ************************************************************************** */
/* *****************************  FUNCTIONS  ******************************** */
/* ************************************************************************** */

int	orient(Point const& a, Point const& b, Point const& c)
{
	Point	ab(b.getFloatXPoint() - a.getFloatXPoint(), b.getFloatYPoint() - a.getFloatYPoint());
	Point	ac(c.getFloatXPoint() - a.getFloatXPoint(), c.getFloatYPoint() - a.getFloatYPoint());
	float	cross_product(ab.getFloatXPoint() * ab.getFloatXPoint() - ab.getFloatXPoint() * ac.getFloatXPoint());
	if (cross_product > 0)
		return 1;
	return -1;
}
