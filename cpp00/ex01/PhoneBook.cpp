/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:45:52 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/05 21:58:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::validateInput(const std::string& input) {
	if (input.length() > 10) {
		return input.substr(0, 9) + ".";
	}
	return input;
}

void PhoneBook::add() {
	Contact contact;
	std::string input;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	contact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	contact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	contact.setNickName(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	contact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	contact.setDarkestSecret(input);

	this->contacts[this->index % 8] = contact;
	this->index++;
	std::cout << "🎉🎉🎉 Entry '" << contact.getFirstName() << "' has been added!" << std::endl;
}

void PhoneBook::search() {
	displayContactEntries();
	std::cout << "Enter index to view contact detail: ";
	int index = -1;
	std::cin >> index;
	std::cin.ignore(1024, '\n');
	if (std::cin.fail() || index < 0 || index >= 8) {
		std::cout << "Oops! You've entered an invalid index 😅" << std::endl;
		std::cin.clear();
		return;
	}
	displayContact(this->contacts[index]);
}

void PhoneBook::displayContactEntries() {
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout
			<< std::setw(10) << std::right << i << "|"
			<< std::setw(10) << std::right << validateInput(this->contacts[i].getFirstName()) << "|"
			<< std::setw(10) << std::right << validateInput(this->contacts[i].getLastName()) << "|"
			<< std::setw(10) << std::right << validateInput(this->contacts[i].getNickName()) << "\n";
	}
	std::cout << std::endl;
}

void PhoneBook::displayContact(const Contact& contact) {
	std::cout << "First name: " << contact.getFirstName() << "\n";
	std::cout << "Last name: " << contact.getLastName() << "\n";
	std::cout << "Nickname: " << contact.getNickName() << "\n";
	std::cout << "Phone number: " << contact.getPhoneNumber() << "\n";
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::exit() {
	std::cout << "See you again 👋!" << std::endl;
}
