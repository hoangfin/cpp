/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:34:15 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 02:00:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria() {
	std::cout << "Ice default constructor called" << std::endl;
	_type = "ice";
}

Ice::Ice(const Ice& ice) : AMateria(ice) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& ice) {
	std::cout << "Ice copy assignment called" << std::endl;
	if (this != &ice) {
		AMateria::operator=(ice);
	}
	return (*this);
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "Ice: '* shoots an ice bolt at " << target.getName() << " *'" << std::endl;
}