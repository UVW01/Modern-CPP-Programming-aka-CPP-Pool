/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:09:25 by mnaimi            #+#    #+#             */
/*   Updated: 2022/10/07 20:08:34 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP_
# define DIAMONDTRAP_HPP_

/* ************************************************************************** */
/* ****************************   INCLUDES   ******************************** */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

/* ************************************************************************** */
/* *****************************   CLASSES   ******************************** */
/* ************************************************************************** */

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	name;

	public:
		DiamondTrap( void );
		DiamondTrap( std::string );
		DiamondTrap( DiamondTrap const& );
		using FragTrap::operator=;
		using ScavTrap::operator=;
		void operator = ( DiamondTrap const& );
		~DiamondTrap( void );

		void	whoAmI( void );
};

#endif
