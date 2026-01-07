/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:01:49 by jweber            #+#    #+#             */
/*   Updated: 2026/01/07 11:06:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

#define BUFFER_SIZE 256

Account::Account()
{
	return ;
}

void	Account::_displayTimestamp(void)
{
    std::time_t result = std::time(NULL);
	std::tm		*result2 = std::localtime(&result);
	char		buffer[BUFFER_SIZE];
	std::strftime(buffer, BUFFER_SIZE, "%Y%m%d_%H%M%S", result2);
	std::cout << "[" << buffer << "] ";
}

int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;
int	Account::_nbAccounts;

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	this->_nbAccounts += 1;
	this->_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
		<< "total:" << Account::getTotalAmount() << ";"
		<< "deposits:" << Account::getNbDeposits() << ";"
		<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount + deposit << ";"
		<< "nb_deposits:" << this->_nbDeposits + 1
		<< std::endl;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "withdrawal:";
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals +=1;
		std::cout << withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
		return (0);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (1);
	}
}

int		Account::checkAmount( void ) const
{
	return (0);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
	return ;
}
