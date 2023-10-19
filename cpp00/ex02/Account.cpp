/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Degef <dsium@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:24:59 by Degef             #+#    #+#             */
/*   Updated: 2023/08/17 20:38:25 by Degef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// Constructor implementation
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
                                       _amount(initial_deposit),
                                       _nbDeposits(0),
                                       _nbWithdrawals(0) {
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount 
			  << ";closed" << std::endl;
}

// Static member initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Definition of the static member function getNbAccounts
int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	
    _displayTimestamp();
    std::cout << "index:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() 
			  << std::endl;
}

void Account::makeDeposit(int deposit) {
	
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amout:" << _amount - deposit
              << ";deposits:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits 
			  << std::endl;
}

bool Account::makeWithdrawal(int withdraw) {
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		 << ";p_amout:" << _amount;	
	if (withdraw > _amount) {
		std::cout << ";withdrawal: refused"
		<< std::endl;
		return false;
	} else {
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdraw
				  << ";amount:" << _amount - withdraw
				  << "nb_withdrawals:" << _nbWithdrawals
			 	  << std::endl;
		return true;
	}
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t currentTime = std::time(NULL);
    struct std::tm* localTimeInfo = std::localtime(&currentTime);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTimeInfo);

    std::cout << "[" << buffer << "] ";
}
