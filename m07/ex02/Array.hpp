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
#include <exception>

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

template <typename T>
class Array
{
	private:
		uint	m_size;
		T*		m_ptrToArr;
	public:
		Array(void);
		Array(uint);
		Array(Array const &);
		Array &operator=(Array const &);
		~Array(void);

		T		&operator[](size_t);
		uint	getSize(void) const;
		T const &getArrayElement(size_t) const;
		void	setArrayElement(size_t, T);
};

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void): m_size(0)
{
	std::cout << "Array Default constructor called" << std::endl;
	m_ptrToArr = new T [m_size];
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

template <typename T>
Array<T>::Array(uint size): m_size(size)
{
	std::cout << "Array Default constructor called" << std::endl;
	m_ptrToArr = new T [m_size];
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

template <typename T>
Array<T>::Array(Array const &obj): m_size(obj.m_size)
{
	std::cout << "Array Copy constructor called" << std::endl;
	m_ptrToArr = new T [m_size];
	for (size_t i = 0; i < m_size; i++)
		m_ptrToArr[i] = obj.m_ptrToArr[i];
	return;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

template <typename T>
Array<T> &Array<T>::operator=(Array const &obj)
{
	if (this == &obj)
		return (*this);
	std::cout << "Array Copy assignment operator called" << std::endl;
	delete [] m_ptrToArr;
	m_size = obj.m_size;
	m_ptrToArr = new T [m_size];
	for (size_t i = 0; i < m_size; i++)
		m_ptrToArr[i] = obj.m_ptrToArr[i];
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Array Destructor called" << std::endl;
	delete [] m_ptrToArr;
	return;
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

template <typename T>
T	&Array<T>::operator[](size_t index)
{
	if (index >= m_size)
		throw std::out_of_range("Index out of range");
	return (m_ptrToArr[m_size]);
}

#endif