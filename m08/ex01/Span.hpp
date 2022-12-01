/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/17 00:13:37 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP_
#define SPAN_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

class Span
{
	private:
		unsigned int		m_N;
		std::vector<int>	m_vec;

	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const &);
		Span &operator=(Span const &);
		~Span(void);

		void	addNumber(int);
		long	shortestSpan(void) const;
		long	longestSpan(void) const;
		void	addRange(std::vector<int>::iterator begin, \
			std::vector<int>::iterator end);

};

#endif
