/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 08:04:22 by mnaimi            #+#    #+#             */
/*   Updated: 2022/07/30 18:15:10 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Contacts
{
	protected:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook
{
	public:
		Contacts contacts[8];
	
	void	display_contact()
};

void	print_commands(void)
{
	std::cout << std::endl << "\e[4;1mAvailable commands:\e[0m" << std::endl;
	std::cout << "\e[1mADD   \e[0m save a new contact" << std::endl;
	std::cout << "\e[1mSEARCH\e[0m display a specific contact" << std::endl;
	std::cout << "\e[1mEXIT  \e[0m \e[2m(self-explanatory)\e[0m" << std::endl;
}

int main(void)
{
	PhoneBook		phonebook;
	std::string		command;

	std::cout << "Please enter the requested command: " << std::endl;
	std::cin >> command;
	print_commands();
	
}
