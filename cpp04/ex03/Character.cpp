/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:02:40 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/21 01:08:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("Undefined") {
	for (int i = 0; i < 4; i++) {
		_materias[i] = nullptr;
	}
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_materias[i] = nullptr;
	}
}

Character::Character(const Character& character) : _name(character._name) {
	for (int i = 0; i < 4; i++) {
		if (character._materias[i] != nullptr) {
			_materias[i] = character._materias[i]->clone();
		}
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete _materias[i];
		_materias[i] = nullptr;
	}
}

Character& Character::operator=(const Character& character) {
	if (this != &character) {
		_name = character._name;
		for (int i = 0; i < 4; i++) {
			delete _materias[i];
			_materias[i] = nullptr;
			if (character._materias[i] != nullptr) {
				_materias[i] = character._materias[i]->clone();
			}
		}
	}
	return (*this);
}

const std::string& Character::getName() const {
	return _name;
}

AMateria* Character::getMateria(int idx) const {
	if (idx < 0 || idx >= 4 || _materias[idx] == nullptr)
		return nullptr;
	return _materias[idx];
}

void Character::equip(AMateria* m) {
	if (m == nullptr)
		return;
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == nullptr) {
			_materias[i] = m->clone();
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		return;
	}
	_materias[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || _materias[idx] == nullptr) {
		return;
	}
	_materias[idx]->use(target);
}
