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

// ************************************************************************** //
//                          Static Member Variables                           //
// ************************************************************************** //

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// ************************************************************************** //
//                         Constructor / Destructor                           //
// ************************************************************************** //

Account::Account( int initial_deposit )
{
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;

	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:"  << this->_amount << ";";
	std::cout << "created" << std::endl;
	return ;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

Account::~Account(void)
{
	Account::_nbAccounts -= 1;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:"  << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

// ************************************************************************** //
//                              Static Functions                              //
// ************************************************************************** //

int		Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

int		Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

int		Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

int		Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:"  << Account::getTotalAmount() << ";";
	std::cout << "deposits:"  << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:"  << Account::getNbWithdrawals() << std::endl;
}

// ************************************************************************** //
//                              Public Methods                                //
// ************************************************************************** //

void	Account::makeDeposit( int deposit )
{
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	this->_amount += deposit;
	this->_nbDeposits += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:"  << Account::checkAmount() << ";";
	std::cout << "deposit:"  << deposit << ";";
	std::cout << "amount:"  << Account::checkAmount() << ";";
	std::cout << "nb_deposits:"  << this->_nbDeposits << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

bool	Account::makeWithdrawal( int withdrawal )
{
	bool	status = false;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:"  << Account::checkAmount() << ";";

	if (this->_amount < withdrawal)
		std::cout << "withdrawal:refused";
	else
	{
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;

		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;

		std::cout << "withdrawal:"  << withdrawal << ";";
		std::cout << "amount:"  << Account::checkAmount() << ";";
		std::cout << "nb_withdrawals:"  << this->_nbWithdrawals;

		status = true;
	}
	std::cout << std::endl;
	return (status);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:"  << Account::checkAmount() << ";";
	std::cout << "deposits:"  << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

void	Account::_displayTimestamp( void )
{
	std::time_t		t = std::time(nullptr);
    std::tm			tm = *std::localtime(&t);

	std::cout << "[";
	std::cout << std::put_time(&tm, "%Y%m%d_%H%M%S");
	std::cout << "] ";
}
