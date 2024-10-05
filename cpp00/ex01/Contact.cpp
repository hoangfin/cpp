/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:01:13 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/05 21:46:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(
	const std::string& firstName,
	const std::string& lastName,
	const std::string& nickName,
	const std::string& phoneNumber,
	const std::string& darkestSecret
)
	: firstName(firstName)
	, lastName(lastName)
	, nickName(nickName)
	, phoneNumber(phoneNumber)
	, darkestSecret(darkestSecret) {
}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	this->lastName = lastName;
}

void Contact::setNickName(const std::string& nickName) {
	this->nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	this->darkestSecret = darkestSecret;
}

const std::string& Contact::getFirstName() const  {
	return firstName;
}

const std::string& Contact::getLastName() const {
	return lastName;
}

const std::string& Contact::getNickName() const {
	return nickName;
}

const std::string& Contact::getPhoneNumber() const {
	return phoneNumber;
}

const std::string& Contact::getDarkestSecret() const {
	return darkestSecret;
}
