/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 08:04:22 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/03 13:49:45 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

/* -- Notes: ---------------------------------------------------------------- *\
\* -------------------------------------------------------------------------- */

void	PrintCommands(void)
{
	std::cout << std::endl << "\e[4;1mAvailable commands:\e[0m" << std::endl;
	std::cout << "\e[1mADD   \e[0m save a new contact" << std::endl;
	std::cout << "\e[1mSEARCH\e[0m display a specific contact" << std::endl;
	std::cout << "\e[1mEXIT  \e[0m \e[2m(self-explanatory)\e[0m" << std::endl;
}

/* -- Notes: ---------------------------------------------------------------- *\
\* -------------------------------------------------------------------------- */

int main(void)
{
	PhoneBook		phonebook;
	std::string		cmd;

	PrintCommands();
	while (1)
	{
		std::cout << std::endl << "Please enter the requested command: ";
		std::cin >> cmd;

		if (cmd.compare("ADD") == 0)
			phonebook.add_contact();
		else if (cmd.compare("SEARCH") == 0)
			phonebook.search_contact(&phonebook, cmd);
		else if (cmd.compare("EXIT") == 0)
			exit(EXIT_SUCCESS);
		else
			std::cout << "Invalid command, Try Again" << std::endl;
	}	
	return (0);
}
