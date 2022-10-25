/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP_
# define POINT_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

class Point
{
	private:
		Fixed const x_;
		Fixed const y_;

	public:
		Point( void );
		~Point( void );

		Point( float const , float const );
		Point( Point const& );
		void	operator = ( Point const& );

		Fixed&	getXPoint( void ) const;
		Fixed&	getYPoint( void ) const;

		float	getFloatXPoint( void ) const;
		float	getFloatYPoint( void ) const;
};

/* ************************************************************************** */
/* ****************************   PROTOTYPES   ****************************** */
/* ************************************************************************** */

int		orient( Point const&, Point const&, Point const& );
bool	bsp( Point const, Point const, Point const, Point const );

#endif
