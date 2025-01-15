#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << MAGENTA << " index:" << _accountIndex << ";amount:"
			  << _amount << ";deposits:" << _nbDeposits << ";withdrawals:"
			  << _nbWithdrawals << RESET << std::endl;
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << YELLOW << "[" << (now->tm_year + 1900) << "-"
			  << std::setw(2) << std::setfill('0') << (now->tm_mon + 1) << "-"
			  << std::setw(2) << std::setfill('0') << now->tm_mday << " "
			  << std::setw(2) << std::setfill('0') << now->tm_hour << ":"
			  << std::setw(2) << std::setfill('0') << now->tm_min << ":"
			  << std::setw(2) << std::setfill('0') << now->tm_sec << "]" << RESET;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << MAGENTA <<" accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:";
	std::cout << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << RESET << std::endl;
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << MAGENTA << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << RESET << std::endl;
}

Account::Account( void ) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << MAGENTA << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << RESET << std::endl;
	_totalAmount -= _amount;
	_nbAccounts--;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << MAGENTA <<" index:" << _accountIndex << ";p_amount:" << _amount << RESET;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << MAGENTA <<";deposit:" << deposit
			  << ";amount:" << _amount << ";nb_deposits:"
			  << _nbDeposits << RESET << std::endl;
}


bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << MAGENTA << " index:" << _accountIndex << ";p_amount:" << _amount << RESET;
	if (withdrawal > _amount)
	{
		std::cout << RED << ";withdrawal:refused" << RESET << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << MAGENTA <<";withdrawal:" << withdrawal
				  << ";amount:" << _amount << ";nb_withdrawals:"
				  << _nbWithdrawals<< RESET << std::endl;
		return (true);
	}
}
