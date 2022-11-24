/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:16:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 21:22:46 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP_
#define ARRAY_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

#include <iostream>
#include <string>

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

template <typename T>
class Array
{
	private:
		uint	m_length;
		T*		m_ptrToArr;
	public:
		Array(void);
		Array(uint);
		Array(Array const &);
		Array &operator=(Array const &);
		~Array(void);

		T const	&getArrayElement(size_t) const;
		void	setArrayElement(size_t, T);
};

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void)
{
	std::cout << "Array Default constructor called" << std::endl;
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

template <typename T>
Array<T>::Array(Array const &obj)
{
	std::cout << "Array Copy constructor called" << std::endl;
	for (size_t i = 0; i < m_length; i++)
		setArrayElement(i, obj.getArrayElement(i));
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

template <typename T>
Array<T> &Array<T>::operator=(Array const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "Array Copy assignment operator called" << std::endl;
	for (size_t i = 0; i < m_length; i++)
		setArrayElement(i, obj.getArrayElement(i));
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Array Destructor called" << std::endl;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

template <typename T>
T const	&Array<T>::getArrayElement(size_t index) const
{
	if (index < m_length)
		return (m_ptrToArr[index]);
	return ("");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

template <typename T>
void Array<T>::setArrayElement(size_t index, T element)
{
	if (index < m_length)
		m_ptrToArr[index] = element;
	return;
}
#endif
