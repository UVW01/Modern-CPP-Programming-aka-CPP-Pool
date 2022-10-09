/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 06:53:32 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/03 18:24:54 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
	std::string		stringSTR = "HI THIS IS BRAIN";
	std::string		*stringPTR = &stringSTR;
	std::string		&stringREF = stringSTR;

	std::cout << "stringSTR Memory Address: " << &stringSTR << std::endl;
	std::cout << "stringPTR Memory Address: " << &stringPTR << std::endl;
	std::cout << "stringREF Memory Address: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "stringSTR Value: " << stringSTR << std::endl;
	std::cout << "stringPTR Value: " << *stringPTR << std::endl;
	std::cout << "stringREF Value: " << stringREF << std::endl;
}
