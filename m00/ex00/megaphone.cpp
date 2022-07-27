/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:39:50 by mnaimi            #+#    #+#             */
/*   Updated: 2022/07/27 13:51:02 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

/* -------------------------------------------------------------------------- *\


::		scope resolution operator
endl	manipulator

  Whenever we try to print something of a different type of the thing beore 
it, we use the output operator (<<)
\* -------------------------------------------------------------------------- */
/*
int	main(void)
{
	int	nb1 = 0, nb2 = 0;
	std::cout << "Enter two number here to get their sum:" << std::endl;
	std::cin >> nb1 >> nb2;
	std::cout << "The sum of " << nb1 << " and " << nb2 << " is " << nb1 + nb2
		<< std::endl;
	return (0);
}
*/

namespace Example {
	int test1 = 1337;
	char str[6] = "hello";
}

int	main(void)
{
	int test1 = 42;
	std::cout << Example::test1 << std::endl;
	return (0);
}

