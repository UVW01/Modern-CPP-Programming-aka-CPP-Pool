/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConvertion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:42:31 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/22 22:42:32 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConversion.hpp"


/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

TypeConversion::TypeConversion(void) : m_input("TypeConversion")
{
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

TypeConversion::TypeConversion(const std::string &input): m_input(input)
{
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

TypeConversion::TypeConversion(TypeConversion const &obj): m_input(obj.m_input)
{
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

TypeConversion &TypeConversion::operator=(TypeConversion const &obj)
{
	if (this != &obj)
		m_input = obj.m_input;
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

TypeConversion::~TypeConversion(void)
{
	return;
}

/* ************************************************************************** */
/* ******************************   UTILS    ******************************** */
/* ************************************************************************** */

void	TypeConversion::toChar(void)
{
	try
	{
		std::cout << "char: ";
		int c = stoi(m_input);
		if (isprint(c))
			std::cout << "'" << static_cast<char>(c) << "'";
		else
			std::cout << "Not displayable";
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible";
	}
	std::cout << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	TypeConversion::toInt(void)
{
	try
	{
		std::cout << "int: ";
		int nb = stoi(m_input);
		std::cout << static_cast<int>(nb);
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible";
	}
	std::cout << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	TypeConversion::toFloat(void)
{
	try
	{
		std::cout << "float: ";
		float nb = stof(m_input);
		if (nb - static_cast<int>(nb) == 0)
			std::cout << static_cast<float>(nb) << ".0f";
		else
			std::cout << static_cast<float>(nb) << "f";
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible";
	}
	std::cout << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	TypeConversion::toDouble(void)
{
	try
	{
		std::cout << "double: ";
		double nb = stod(m_input);
		if (nb - static_cast<int>(nb) == 0)
			std::cout << static_cast<double>(nb) << ".0";
		else
			std::cout << static_cast<double>(nb);
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible";
	}
	std::cout << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	TypeConversion::convert(void)
{
	toChar();
	toInt();
	toFloat();
	toDouble();
	return ;
}
