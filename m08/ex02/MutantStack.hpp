/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/27 02:57:14 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANT_STACK_HPP_
#define MUTANT_STACK_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

template <typename T, class Container=std::deque<T> >
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void) : std::stack<T>() { return; };
	MutantStack(MutantStack const & obj) : std::stack<T>(obj) { return; };
	MutantStack &operator=(MutantStack const &obj) {
		std::stack<T>::operator=(obj);
		return (*this);
	};
	~MutantStack(void) { return; };

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }

	reverse_iterator rbegin() { return (this->c.rbegin()); }
	reverse_iterator rend() { return (this->c.rend()); }

	const_iterator cbegin() { return (this->c.cbegin()); }
	const_iterator cend() { return (this->c.cend()); }
};

#endif
