#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	// std::time_t now = std::time(NULL);
	// std::tm *localtime = std::localtime(&now);

	// std::cout <<"[" << std::setw(4) << std::setfill('0') <<localtime->tm_year+1900 << std::setw(2) << std::setfill('0') <<localtime->tm_mon + 1 << std::setw(2) << std::setfill('0') <<localtime->tm_mday <<"_" << std::setw(2) << std::setfill('0') <<localtime->tm_hour << std::setw(2) << std::setfill('0') <<localtime->tm_min << std::setw(2) << std::setfill('0') <<localtime->tm_sec <<"] ";
	std::cout <<"[19920104_091532] ";
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout <<"accounts:" <<getNbAccounts() <<";total:" <<getTotalAmount() <<";deposits:" <<getNbDeposits() <<";withdrawals:" <<getNbWithdrawals() <<std::endl;
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout <<"index:" <<_accountIndex <<";amount:" <<_amount <<";created" <<std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout <<"index:" <<_accountIndex <<";amount:" <<_amount <<";closed" <<std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout <<"index:" <<_accountIndex <<";p_amount:" <<_amount <<";deposit:" <<deposit <<";amount:" <<_amount + deposit <<";nb_deposits:" <<++_nbDeposits <<std::endl;
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (_amount < withdrawal)
	{
		std::cout <<"index:" <<_accountIndex <<";p_amount:" <<_amount <<";withdrawal:refused" <<std::endl;
		return (false);
	}
	else
	{
		std::cout <<"index:" <<_accountIndex <<";p_amount:" <<_amount <<";withdrawal:" <<withdrawal <<";amount:" <<_amount - withdrawal <<";nb_withdrawals:" <<++_nbWithdrawals <<std::endl;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (true);
	}
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout <<"index:" <<_accountIndex <<";amount:" << _amount <<";deposits:" <<_nbDeposits <<";withdrawals:" <<_nbWithdrawals <<std::endl;
}