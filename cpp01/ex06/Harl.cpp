/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:14:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/11 15:32:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
	std::cout
			<< "[ DEBUG ]\nI love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			<< std::endl;
}

void Harl::info() {
	std::cout
			<< "[ INFO ]\nI cannot believe adding extra bacon costs more money. "
			<< "You didn't put enough bacon in my burger! "
			<< "If you did, I wouldn't be asking for more!"
			<< std::endl;
}

void Harl::warning() {
	std::cout
			<< "[ WARNING ]\nI think I deserve to have some extra bacon for free. "
			<< "I've been coming for years whereas you started working here since last month."
			<< std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Logger loggers[4] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			break;
		i++;
	}
	switch (i) {
		case 0:
			(this->*loggers[0])();
			std::cout << std::endl;
		case 1:
			(this->*loggers[1])();
			std::cout << std::endl;
		case 2:
			(this->*loggers[2])();
			std::cout << std::endl;
		case 3:
			(this->*loggers[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
