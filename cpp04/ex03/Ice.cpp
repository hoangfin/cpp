/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:34:15 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/21 01:11:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria() {
	_type = "ice";
}

Ice::Ice(const Ice& ice) : AMateria(ice) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& ice) {
	if (this != &ice) {
		AMateria::operator=(ice);
	}
	return (*this);
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}