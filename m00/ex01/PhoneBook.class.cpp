/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:41:45 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/03 15:58:07 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

/* -------------------------------------------------------------------------- *\
							Constructor/Destructor
\* -------------------------------------------------------------------------- */
PhoneBook::PhoneBook(void)
{

	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/* -------------------------------------------------------------------------- *\
								Other methods
\* -------------------------------------------------------------------------- */

static std::string truncate(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

static void display_info(Contact *contact)
{
	std::cout << "     Index|  First N.|   Last N.|   Nick N." << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|" \
			<< std::setw(10) << truncate((contact[i]).get_member(0)) << "|" \
			<< std::setw(10) << truncate((contact[i]).get_member(1)) << "|" \
			<< std::setw(10) << truncate((contact[i]).get_member(2)) \
			<< std::endl;
	}
}

int PhoneBook::search_contact(PhoneBook *phonebook, const std::string str)
{
	display_info((*phonebook).contacts);
	(void)str;
	return (0);
}


int PhoneBook::add_contact(void)
{
	std::string		prompt;
	std::string		fields[5] = {
		"First Name\t:", 
		"Last Name\t:", 
		"Nickname\t:", 
		"Phone Number\t:", 
		"Darkest Secret\t:"
	};
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << std::endl << fields[i];
	//	std::cin >> prompt;
		
	}
	return (0);
}
