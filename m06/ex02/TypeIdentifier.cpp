/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeIdentifier.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:42:31 by mnaimi            #+#    #+#             */
/*   Updated: 2022/11/22 22:42:32 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeIdentifier.hpp"

/* ************************************************************************** */
/* *********************   CONSTRUCTOR / DESTRUCTOR    ********************** */
/* ************************************************************************** */

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

A::~A()
{
	std::cout << "A destructor called" << std::endl;
}

B::~B()
{
	std::cout << "B destructor called" << std::endl;
}

C::~C()
{
	std::cout << "C destructor called" << std::endl;
}

/* ************************************************************************** */
/* ****************************   FUNCTIONS    ****************************** */
/* ************************************************************************** */

Base	*generate(void)
{
	Base *output = NULL;
	struct timeval	time;

	gettimeofday(&time, NULL);
	srand((time.tv_sec * 1000000) + time.tv_usec);
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			output = new A();
			break;
		case 1:
			output = new B();
			break;
		case 2:
			output = new C();
			break;
		default:
			break;
	}
	return (output);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	identify(Base *p)
{
	char	type = '\0';
	A*		a = dynamic_cast<A*>(p);
	B*		b = dynamic_cast<B*>(p);
	C*		c = dynamic_cast<C*>(p);

	if (a)
		type = 'A';
	else if (b)
		type = 'B';
	else if (c)
		type = 'C';
	std::cout << "Pointer Type is: " << type << std::endl;
}

/* -------------------------------------------------------------------------- */

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Pointer Type is: A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Pointer Type is: B"<< std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Pointer Type is: C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
	}
}
