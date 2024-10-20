/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:28:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/21 01:11:49 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria() {
	_type = "cure";
}

Cure::Cure(const Cure& cure) : AMateria(cure) {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& cure) {
	if (this != &cure) {
		AMateria::operator=(cure);
	}
	return (*this);
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
