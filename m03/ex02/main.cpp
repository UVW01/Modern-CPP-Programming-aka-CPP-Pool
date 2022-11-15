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

#include "FragTrap.hpp"

int main(void)
{
	FragTrap first;
	FragTrap second("Patrick Bateman");
	FragTrap third(second);
	FragTrap forth;
	forth = second;
	ClapTrap *ptr = &first;

	std::cout << std::endl;
	std::cout << "1st" << std::endl;
	std::cout << "Name:" << first.getName() << std::endl;
	std::cout << "HitPoints: " << first.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << first.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << first.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "2nd" << std::endl;
	std::cout << "Name:" << second.getName() << std::endl;
	std::cout << "HitPoints: " << second.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << second.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << second.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "3rd" << std::endl;
	std::cout << "Name:" << third.getName() << std::endl;
	std::cout << "HitPoints: " << third.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << third.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << third.getAttackDamage() << std::endl;
	std::cout << std::endl;

	std::cout << "4th" << std::endl;
	std::cout << "Name:" << forth.getName() << std::endl;
	std::cout << "HitPoints: " << forth.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << forth.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage: " << forth.getAttackDamage() << std::endl;
	std::cout << std::endl;

	first.attack("Alien");
	ptr->attack("Alien");
	first.highFivesGuys();
	second.takeDamage(50);
	third.beRepaired(50);
	forth.takeDamage(101);
	forth.attack("Human");
	std::cout << std::endl;

	return (0);
}
