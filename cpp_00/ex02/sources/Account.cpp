#include "Account.hpp"
# include <string>
# include <iostream>
#include <chrono>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{

	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
}

void	Account::makeDeposit(int deposit )
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";"
		<< "p_amount:" << _amount << ";"; 
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "deposit:" << deposit << ";" << "amount:"
		<< _amount << ";" << "nb_deposits:" << _nbDeposits <<";"
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";"
		<< "p_amount:" << _amount << ";"; 
	if (_amount - withdrawal >= 0)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "deposit:" << withdrawal << ";" << "amount:"
			<< _amount << ";" << "nb_withdrawals:" << _nbWithdrawals << ";"
			<< std::endl;
		return (true);
	}
	std::cout << "withdrawal:refused" << std::endl;
	return false;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" <<_nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t rawtime;
  	struct tm * timeinfo;
	char buffer [17];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,80,"[%G%m%d_%H%M%S]",timeinfo);
	std::cout << buffer << " ";
	return ;
}

