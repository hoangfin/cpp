/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:58:07 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 15:52:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : _amaterias(new AMateria*[MateriaSource::MAX_NUM_OF_SOURCES]) {
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MateriaSource::MAX_NUM_OF_SOURCES; i++) {
		_amaterias[i] = nullptr;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ms) : _amaterias(new AMateria*[MateriaSource::MAX_NUM_OF_SOURCES]) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < MateriaSource::MAX_NUM_OF_SOURCES; i++) {
		_amaterias[i] = ms._amaterias[i]->clone();
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MateriaSource::MAX_NUM_OF_SOURCES; i++) {
		delete _amaterias[i];
		_amaterias[i] = nullptr;
	}
	delete[] _amaterias;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms) {
	std::cout << "MateriaSource copy assignment called" << std::endl;
	if (this != &ms) {
		for (int i = 0; i < MateriaSource::MAX_NUM_OF_SOURCES; i++) {
			delete _amaterias[i];
			_amaterias[i] = ms._amaterias[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* amateria) {
	if (amateria == nullptr)
		return;
	for (int i = 0; i < MateriaSource::MAX_NUM_OF_SOURCES; i++) {
		if (_amaterias[i] == nullptr) {
			_amaterias[i] = amateria;
			return;
		}
	}
	std::cout << "Reached limit, couldn't learn more materia!" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < MateriaSource::MAX_NUM_OF_SOURCES; i++) {
		if (_amaterias[i] != nullptr && _amaterias[i]->getType() == type) {
			return _amaterias[i]->clone();
		}
	}
	return 0;
}
