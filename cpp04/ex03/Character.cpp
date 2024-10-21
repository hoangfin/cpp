/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:02:40 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/21 18:02:10 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
	: _name("Undefined")
	, _index(0)
	, _size(4)
	, _removedMaterias(new AMateria*[4]) {
	for (int i = 0; i < 4; i++) {
		_materias[i] = nullptr;
		_removedMaterias[i] = nullptr;
	}
}

Character::Character(const std::string& name)
	: _name(name)
	, _index(0)
	, _size(4)
	, _removedMaterias(new AMateria*[4]) {
	for (int i = 0; i < 4; i++) {
		_materias[i] = nullptr;
		_removedMaterias[i] = nullptr;
	}
}

Character::Character(const Character& character)
	: _name(character._name)
	, _index(character._index)
	, _size(character._size)
	, _removedMaterias(new AMateria*[character._size]) {
	for (int i = 0; i < 4; i++) {
		_materias[i] = nullptr;
		if (character._materias[i] != nullptr) {
			_materias[i] = character._materias[i]->clone();
		}
	}
	for (int i = 0; i < character._size; i++) {
		_removedMaterias[i] = nullptr;
		if (character._removedMaterias[i] != nullptr) {
			_removedMaterias[i] = character._removedMaterias[i]->clone();
		}
	}
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete _materias[i];
		_materias[i] = nullptr;
	}
	for (int i = 0; i < _size; i++) {
		delete _removedMaterias[i];
		_removedMaterias[i] = nullptr;
	}
	delete[] _removedMaterias;
}

Character& Character::operator=(const Character& character) {
	if (this != &character) {
		_name = character._name;
		_index = character._index;
		for (int i = 0; i < 4; i++) {
			delete _materias[i];
			_materias[i] = character._materias[i];
		}
		for (int i = 0; i < _size; i++) {
			delete _removedMaterias[i];
		}
		delete[] _removedMaterias;
		_size = character._size;
		_removedMaterias = new AMateria*[_size];
		for (int i = 0; i < _size; i++) {
			_removedMaterias[i] = nullptr;
			if (character._materias[i] != nullptr) {
				_removedMaterias[i] = character._removedMaterias[i]->clone();
			}
		}
	}
	return (*this);
}

void Character::_push(AMateria* m) {
	_removedMaterias[_index] = m;
	if (_index == _size - 1) {
		_size *= 1.5;
		AMateria** temp = new AMateria*[_size];
		for (int i = 0; i <= _index; i++) {
			temp[i] = _removedMaterias[i];
		}
		delete[] _removedMaterias;
		for (int i = _index + 1; i < _size; i++) {
			temp[i] = nullptr;
		}
		_removedMaterias = temp;
	}
	_index++;
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m == nullptr)
		return;
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == nullptr) {
			_materias[i] = m;
			return;
		}
	}
	delete m;
	std::cout << "Unable to equip, all slots are occupied!" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		return;
	}
	_push(_materias[idx]);
	_materias[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || _materias[idx] == nullptr) {
		return;
	}
	_materias[idx]->use(target);
}
