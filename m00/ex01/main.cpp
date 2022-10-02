/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 08:04:22 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/09 10:30:24 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

/* -------------------------------------------------------------------------- */

void	print_commands(void)
{
	std::cout << std::endl << "\e[4;1mAvailable commands:\e[0m" << std::endl;
	std::cout << "\e[1mSEARCH\e[0m display a specific contact" << std::endl;
	std::cout << "\e[1mADD   \e[0m save a new contact" << std::endl;
	std::cout << "\e[1mEXIT  \e[0m \e[2m(self-explanatory)\e[0m" << std::endl;
	std::cout << std::endl;
}

/* -------------------------------------------------------------------------- */

int main(void)
{
	std::string		cmd;
	PhoneBook		phonebook;
	int				contact_index = 0; 

	print_commands();
	while (true)
	{
		std::cout << "Please enter the requested command: ";
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
		{
			phonebook.add_contact(contact_index++);
			contact_index %= 8;
		}
		else if (cmd.compare("SEARCH") == 0)
			phonebook.search_contact(&phonebook);
		else if (cmd.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Invalid command, Try Again";
		std::cout << std::endl;
	}	
	return (0);
}
