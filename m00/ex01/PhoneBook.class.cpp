/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:41:45 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/09 10:38:47 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <string>

/* -------------------------------------------------------------------------- *\
							Constructor/Destructor
\*-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -*/

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

/*-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -*/

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

/* -------------------------------------------------------------------------- *\
								Other methods
\*-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -*/

static std::string truncate(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

static void display_info(Contact *contact)
{
	std::cout << std::endl;
	std::cout << "     Index|  First N.|   Last N.|   Nick N." << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << truncate((contact[i]).get_member(0)) << "|"
			<< std::setw(10) << truncate((contact[i]).get_member(1)) << "|"
			<< std::setw(10) << truncate((contact[i]).get_member(2))
			<< std::endl;
	}
}

int PhoneBook::search_contact(PhoneBook *phonebook) {
	std::string		index_str;
	int				index;
	std::string		fields[5] = { "First Name\t: ", "Last Name\t: ",
		"Nickname\t: ", "Phone Number\t: ", "Darkest Secret\t: " };

	display_info(phonebook->contacts);
	while (true)
	{
		std::cout << "Please enter the desired contact's index: ";
		std::getline(std::cin, index_str);
		if (index_str.size() == 1 && std::isdigit(index_str[0]) && index_str[0] < '8')
			break ;
		std::cout << "Invalid input" << std::endl;
	}		
	index = std::stoi(index_str);
	for (int i = 0; i < 5; i++)
	{
		std::cout << fields[i] << this->contacts[index].get_member(i);
		std::cout << std::endl;
	}
	return (0);
}

/*-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -*/

int PhoneBook::add_contact(int contact_index)
{
	std::string prompt;
	std::string fields[5] = { "First Name\t: ", "Last Name\t: ",
		"Nickname\t: ", "Phone Number\t: ", "Darkest Secret\t: " };

	for (int i = 0; i < 5; i++)
	{
		std::cout << fields[i];
		std::getline(std::cin, prompt);
		if (!prompt.empty())
			this->contacts[contact_index].set_member(prompt, i);
		else
		{
			std::cout << "Invalid value" << std::endl;
			--i;
		}
	}
	return (0);
}

/*-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -*/
