#include "Account.hpp"

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbDeposits;
}
void	Account::displayAccountsInfos( void )
{
}

void	Account::makeDeposit( int deposit )
{
	_amount +=deposit;
	_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount || withdrawal < 0)
		return false;
	_amount -=withdrawal;
	_nbWithdrawals++;
	return true;
}

int	Account::checkAmount( void ) const
{
	return _amount;
}
void	Account::displayStatus( void ) const
{}

Account(int initial_deposit)
{

}
