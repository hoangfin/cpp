/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:58:07 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/21 01:10:07 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_amaterias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ms) {
	for (int i = 0; i < 4; i++) {
		_amaterias[i] = ms._amaterias[i]->clone();
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		delete _amaterias[i];
		_amaterias[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms) {
	if (this != &ms) {
		for (int i = 0; i < 4; i++) {
			delete _amaterias[i];
			_amaterias[i] = ms._amaterias[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* amateria) {
	if (amateria == nullptr)
		return;
	for (int i = 0; i < 4; i++) {
		if (_amaterias[i] == nullptr) {
			_amaterias[i] = amateria->clone();
			return;
		}
	}
	std::cout << "Reached limit, couldn't learn more materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (_amaterias[i] != nullptr && _amaterias[i]->getType() == type) {
			return _amaterias[i]->clone();
		}
	}
	return 0;
}
