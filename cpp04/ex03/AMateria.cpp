/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:54:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/21 01:08:33 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("Undefined AMaterial") {}

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& amateria) : _type(amateria._type) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& materia) {
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