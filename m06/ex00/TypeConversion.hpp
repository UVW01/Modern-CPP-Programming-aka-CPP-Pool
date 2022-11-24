/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:16:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 21:22:46 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TYPE_CONVERSION_HPP_
#define TYPE_CONVERSION_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include <iomanip>

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

class TypeConversion
{
	public:
		std::string	m_input;

		TypeConversion(void);
		TypeConversion(const std::string &);
		TypeConversion(TypeConversion const&);
		TypeConversion& operator=(TypeConversion const&);
		~TypeConversion(void);

		void	toChar(void);
		void	toInt(void);
		void	toFloat(void);
		void	toDouble(void);
		void	convert(void);
};

/* ************************************************************************** */
/* ****************************   PROTOTYPES   ****************************** */
/* ************************************************************************** */

#endif
