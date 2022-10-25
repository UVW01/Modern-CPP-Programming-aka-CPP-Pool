/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP_
# define FIXED_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

# include <iostream>
# include <cmath>

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

class Fixed
{
	private:
		int					fp_;
		static const int	fract_bits_no_ = 8;

	public:
		Fixed( void );
		~Fixed( void );

		Fixed( Fixed const& );
		Fixed( int const value );
		Fixed( float const value );

		void	operator = ( Fixed const& );

		bool	operator >  ( Fixed const& );
		bool	operator <  ( Fixed const& );
		bool	operator >= ( Fixed const& );
		bool	operator <= ( Fixed const& );
		bool	operator == ( Fixed const& );
		bool	operator != ( Fixed const& );

		Fixed	operator + ( Fixed const& );
		Fixed	operator - ( Fixed const& );
		Fixed	operator * ( Fixed const& );
		Fixed	operator / ( Fixed const& );

		Fixed&	operator ++ ( void );
		Fixed&	operator -- ( void );
		Fixed	operator ++ ( int );
		Fixed	operator -- ( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed&	min( Fixed&, Fixed& );
		static Fixed&	max( Fixed&, Fixed& );
		static Fixed&	min( Fixed const&, Fixed const& );
		static Fixed&	max( Fixed const&, Fixed const& );
};

/* ************************************************************************** */
/* ****************************   PROTOTYPES   ****************************** */
/* ************************************************************************** */

std::ostream&	operator << ( std::ostream& , Fixed const& );

#endif
