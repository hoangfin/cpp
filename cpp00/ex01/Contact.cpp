/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:01:13 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/06 20:53:43 by hoatran          ###   ########.fr       */
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
	: _firstName(firstName)
	, _lastName(lastName)
	, _nickName(nickName)
	, _phoneNumber(phoneNumber)
	, _darkestSecret(darkestSecret) {
}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName) {
	_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	_lastName = lastName;
}

void Contact::setNickName(const std::string& nickName) {
	_nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	_darkestSecret = darkestSecret;
}

const std::string& Contact::getFirstName() const  {
	return _firstName;
}

const std::string& Contact::getLastName() const {
	return _lastName;
}

const std::string& Contact::getNickName() const {
	return _nickName;
}

const std::string& Contact::getPhoneNumber() const {
	return _phoneNumber;
}

const std::string& Contact::getDarkestSecret() const {
	return _darkestSecret;
}
