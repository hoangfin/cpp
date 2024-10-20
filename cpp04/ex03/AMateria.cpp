/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:54:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 15:46:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("Undefined AMaterial") {
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& amateria) : _type(amateria._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& materia) {
	std::cout << "AMateria copy assignment called" << std::endl;
	if (this != &materia) {
		this->_type = materia._type;
	}
	return (*this);
}

const std::string& AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria: '* ..... " << target.getName() << " .... *'" << std::endl;
}