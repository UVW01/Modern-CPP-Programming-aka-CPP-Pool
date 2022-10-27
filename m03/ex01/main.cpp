/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int	main( void )
{
	// ScavTrap	first;
	ScavTrap	second("Monster");
	std::cout << std::endl;

	// ScavTrap	third(second);
	ScavTrap	forth;
	std::cout << std::endl;

	forth = second;
	std::cout << std::endl;

	// std::cout << "first" << std::endl;
	// std::cout << first.getName() << " " << first.getHitPoints() << " ";
	// std::cout << first.getAttackDamage() << " " << first.getEnergyPoints();
	// std::cout << std::endl;

	std::cout << "Second:" << std::endl;
	std::cout << second.getName() << " " << second.getHitPoints() << " ";
	std::cout << second.getAttackDamage() << " " << second.getEnergyPoints();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	//second.guardGate();

	// std::cout << "third" << std::endl;
	// std::cout << third.getName() << " " << third.getHitPoints() << " ";
	// std::cout << third.getAttackDamage() << " " << third.getEnergyPoints();
	// std::cout << std::endl;

	// std::cout << "forth" << std::endl;
	// std::cout << forth.getName() << " " << forth.getHitPoints() << " ";
	// std::cout << forth.getAttackDamage() << " " << forth.getEnergyPoints();
	// std::cout << std::endl;

	return (0);
}
