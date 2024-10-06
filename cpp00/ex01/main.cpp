/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:21:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/06 13:49:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phoneBook;

	std::cout << "Welcome to phonebook service! The service allows you to:\n";
	std::cout << " - ADD: save a new contact.\n";
	std::cout << " - SEARCH: display a specific contact.\n";
	std::cout << " - EXIT: quit program and the contacts are lost forever!\n" << std::endl;

	std::string command;
	while (true)
	{
		std::cout << "🤔 What now? (ADD | SEARCH | EXIT) ";
		std::getline(std::cin, command);
		if (command == "EXIT") {
			phoneBook.exit();
			break;
		}
		if (command != "ADD" && command != "SEARCH") {
			std::cout << "Unknown command: " << command << std::endl;
			continue;
		}
		if (command == "ADD") {
			phoneBook.add();
		} else if (command == "SEARCH") {
			phoneBook.search();
		}
	}
	return 0;
}
