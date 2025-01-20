/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-pol <joao-pol@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:51:21 by joao-pol          #+#    #+#             */
/*   Updated: 2025/01/13 16:17:20 by joao-pol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_totalNbDeposits = 1;
	this->_totalNbWithdrawals = 0;
}

Account::Account(void)
{
	this->_accountIndex = _nbAccounts++;
	this->_totalAmount = 0;
	this->_totalNbDeposits = 0;
	this->_totalNbWithdrawals = 0;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{


}

void	Account::_displayTimestamp(void)
{
	time_t now = time(NULL);
    struct std::tm* localTime = localtime(&now);
	int	year = localTime->tm_year + 1900;
	int	mon= localTime->tm_mon + 1;
	int	day = localTime->tm_mday;
	float hour = localTime->tm_hour;
	float min = localTime->tm_min;
	float sec = localTime->tm_sec;
	std::cout << "["
		<< std::setfill('0') << std::setw(4) << year
		<< std::setfill('0') << std::setw(2) << mon
		<< std::setfill('0') << std::setw(2) << day
		<< '_'
		<< std::setfill('0') << std::setw(2) << hour
		<< std::setfill('0') << std::setw(2) << min
		<< std::setfill('0') << std::setw(2) << sec
		<< std::setfill('0') << std::setw(2) << "] "
		<< std::endl;
}

// ~Account( void );

void	Account::makeDeposit( int deposit )
{
	if (deposit < 0) {
		std::cout << "index:" <<_accountIndex << ";amount:" <<_amount << "deposit:refused" << std::endl;
		return ;
	}
	else
	{
		this->_totalNbDeposits++;
		this->_totalAmount += deposit;
	}
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal < 0 || withdrawal > this->_totalAmount) {
		std::cout << "index:" <<_accountIndex << ";amount:" <<_amount << "withdrawal:refused" << std::endl;
		return false ;
	}
	else
	{
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		std::cout << "index:" <<_accountIndex << ";amount:" <<_amount << "withdrawal:" << this->_nbWithdrawals << std::endl;
		return true ;
	}

}
int	Account::checkAmount( void ) const
{
	return (this->_totalAmount);
}
void	Account::displayStatus( void ) const
{

}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";amount:" <<_amount << ";closed" << std::endl;

}
