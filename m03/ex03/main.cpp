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

#include "DiamondTrap.hpp"


int	main( void )
{

	DiamondTrap	second("Monster");

	std::cout << std::endl;
	second.whoAmI();
	std::cout << "HitPoints: " << second.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << second.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << second.getAttackDamage() << std::endl;
	second.attack("Alien");
	second.takeDamage(100);
	second.takeDamage(10);
	second.beRepaired(3);
	std::cout << std::endl;

	return (0);
}
