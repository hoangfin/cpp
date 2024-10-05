/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:21:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/05 21:02:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phoneBook;

	std::cout << "Welcome to phonebook service! The service allows you to:\n";
	std::cout << " - ADD: save a new contact.\n";
	std::cout << " - SEARCH: display a specific contact.\n";
	std::cout << " - EXIT: quit program and the contacts are lost forever!" << std::endl;

	std::string option;
	while (true)
	{
		std::cout << "👉 ADD | SEARCH | EXIT 👈" << std::endl;
		std::getline(std::cin, option);
		if (option == "EXIT") {
			phoneBook.exit();
			break;
		}
		if (option != "ADD" && option != "SEARCH") {
			std::cout << "😿 unsupported option!" << std::endl;
			continue;
		}
		if (option == "ADD") {
			phoneBook.add();
		} else if (option == "SEARCH") {
			phoneBook.search();
		}
	}
	return 0;
}
