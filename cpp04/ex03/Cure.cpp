/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:28:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 02:00:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria() {
	std::cout << "Cure default constructor called" << std::endl;
	_type = "cure";
}

Cure::Cure(const Cure& cure) : AMateria(cure) {
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& cure) {
	std::cout << "Cure copy assignment called" << std::endl;
	if (this != &cure) {
		AMateria::operator=(cure);
	}
	return (*this);
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "Cure: '* heals " << target.getName() << "'s wounds *'" << std::endl;
}
