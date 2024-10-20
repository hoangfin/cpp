/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:02:40 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 16:01:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
	: _name("Undefined")
	, _amaterias(new AMateria*[Character::MAX_SLOTS]) {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < Character::MAX_SLOTS; i++) {
		_amaterias[i] = nullptr;
	}
}

Character::Character(const std::string& name)
	: _name(name)
	, _amaterias(new AMateria*[Character::MAX_SLOTS]) {
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < Character::MAX_SLOTS; i++) {
		_amaterias[i] = nullptr;
	}
}

Character::Character(const Character& character)
	: _name(character._name)
	, _amaterias(new AMateria*[Character::MAX_SLOTS]) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < Character::MAX_SLOTS; i++) {
		_amaterias[i] = character._amaterias[i]->clone();
	}
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < Character::MAX_SLOTS; i++) {
		delete _amaterias[i];
		_amaterias[i] = nullptr;
	}
	delete[] _amaterias;
}

Character& Character::operator=(const Character& character) {
	std::cout << "Character copy assignment called" << std::endl;
	if (this != &character) {
		_name = character._name;
		for (int i = 0; i < Character::MAX_SLOTS; i++) {
			delete _amaterias[i];
			_amaterias[i] = character._amaterias[i]->clone();
		}
	}
	return (*this);
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m == nullptr)
		return;
	for (int i = 0; i < Character::MAX_SLOTS; i++) {
		if (_amaterias[i] == nullptr) {
			_amaterias[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= Character::MAX_SLOTS) {
		return;
	}
	delete _amaterias[idx];
	_amaterias[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= Character::MAX_SLOTS || _amaterias[idx] == nullptr) {
		return;
	}
	_amaterias[idx]->use(target);
}
