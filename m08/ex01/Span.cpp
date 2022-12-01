/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/18 22:27:20 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
/* ********************   CONSTRUCTOR / DESTRUCTOR    *********************** */
/* ************************************************************************** */

Span::Span(void)
	: m_N(0)
{
	std::cout << "Span Default constructor called" << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Span::Span(unsigned int inputN)
	: m_N(inputN)
{
	std::cout << "Span Default constructor called" << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Span::Span(Span const &obj)
	: m_N(obj.m_N)
{
	std::cout << "Span Copy constructor called" << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Span &Span::operator=(Span const &obj)
{
	if (this != &obj)
	{
		std::cout << "Span Copy assignment operator called" << std::endl;
		m_N = obj.m_N;
	}
	return (*this);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Span::~Span(void)
{
	std::cout << "Span Destructor called" << std::endl;
	m_vec.clear();
}

/* ************************************************************************** */
/* ******************************  METHODS  ********************************* */
/* ************************************************************************** */

void	Span::addNumber(int nb)
{
	if (m_vec.size() < m_N)
		m_vec.push_back(nb);
	else
		throw std::runtime_error("No available space left");
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Span::addRange(std::vector<int>::iterator begin, \
	std::vector<int>::iterator end)
{
	if (end - begin <= 0)
		throw std::runtime_error("Invalid iterators");
	else if (m_vec.size() == m_N)
		throw std::runtime_error("No more space left");
	while (m_vec.size() < m_N && begin != end)
		m_vec.push_back(*(begin++));
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

long	Span::shortestSpan(void) const
{
	if (m_vec.size() < 2)
		throw std::runtime_error("No span can be found");

	std::vector<int> cp_vec(m_vec);
	std::sort(cp_vec.begin(), cp_vec.end());
	std::vector<int>::iterator it = cp_vec.begin();
	long s_span = LONG_MAX;
	while (it != cp_vec.end() - 1)
	{
		if (*(it + 1) - *it < s_span)
			s_span = *(it + 1) - *it;
		it++;
	}
	return (s_span);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

long	Span::longestSpan(void) const
{
	if (m_vec.size() < 2)
		throw std::runtime_error("No span can be found");
	long s_span = *std::max_element(m_vec.begin(), m_vec.end());
	s_span -= *std::min_element(m_vec.begin(), m_vec.end());
	return (s_span);
}
