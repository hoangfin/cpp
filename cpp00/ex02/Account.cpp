/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:56:45 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/08 14:51:42 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm *localTime = localtime(&now);
	char format[80];
	std::strftime(format, sizeof(format), "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << format << "]";
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals
			<< std::endl;
}

void Account::makeDeposit(int deposit) {
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = _amount;
	bool has_succeeded = withdrawal <= _amount ? true : false;
	_displayTimestamp();
	if (has_succeeded) {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout
				<< "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	} else {
		std::cout
				<< "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:refused"
				<< std::endl;
	}
	return has_succeeded;
}

int Account::checkAmount(void) const { return _amount; }
