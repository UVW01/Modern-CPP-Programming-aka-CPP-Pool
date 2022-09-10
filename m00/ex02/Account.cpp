/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:37:58 by mnaimi            #+#    #+#             */
/*   Updated: 2022/08/10 21:35:41 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

/* -------------------------------------------------------------------------- */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	Account::_accountIndex = Account::_nbAccounts - 1;
	Account::_amount = initial_deposit;

	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:"  << Account::_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	Account::_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:"  << Account::_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

/* --------------------------------- STATIC --------------------------------- */

int		Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:"  << getTotalAmount() << ";";
	std::cout << "deposits:"  << getNbDeposits() << ";";
	std::cout << "withdrawals:"  << getNbWithdrawals() << std::endl;
}

/* -------------------------------------------------------------------------- */

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:"  << Account::checkAmount() << ";";
	std::cout << "deposit:"  << deposit << ";";
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << "amount:"  << Account::checkAmount() << ";";
	std::cout << "nb_deposits:"  << Account::_nbDeposits << std::endl;
}


bool	Account::makeWithdrawal( int withdrawal )
{
	bool		status = false;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:"  << Account::checkAmount() << ";";
	if (Account::_amount < withdrawal)
		std::cout << "withdrawal:refused";
	else
	{
		Account::_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		std::cout << "withdrawal:"  << withdrawal << ";";
		std::cout << "amount:"  << Account::checkAmount() << ";";
		std::cout << "nb_withdrawals:"  << Account::_nbWithdrawals;
		status = true;
	}
	std::cout << std::endl;
	return (status);
}


int		Account::checkAmount( void ) const
{
	return (Account::_amount);
}


void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";";
	std::cout << "amount:"  << Account::checkAmount() << ";";
	std::cout << "deposits:"  << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

/* -------------------------------------------------------------------------- */

void	Account::_displayTimestamp( void )
{
	std::time_t		t = std::time(nullptr);
    std::tm			tm = *std::localtime(&t);

	std::cout << "[";
	std::cout << std::put_time(&tm, "%Y%m%d_%H%M%S");
	std::cout << "] ";
}


