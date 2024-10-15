/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:50:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 00:28:10 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("undefined")
	, _hitPoints(10)
	, _energyPoints(10)
	, _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name)
	, _hitPoints(10)
	, _energyPoints(10)
	, _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
	: _name(clapTrap._name)
	, _hitPoints(clapTrap._hitPoints)
	, _energyPoints(clapTrap._energyPoints)
	, _attackDamage(clapTrap._attackDamage) {
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
	if (this != &clapTrap) {
		_name = clapTrap._name;
		_hitPoints = clapTrap._hitPoints;
		_energyPoints = clapTrap._energyPoints;
		_attackDamage = clapTrap._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		_attackDamage = 0;
		std::cout << "ClapTrap " << _name << " has 0 hit points, CAN NOT attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		_attackDamage = 0;
		std::cout << "ClapTrap " << _name << " has 0 energy points, CAN NOT attack!" << std::endl;
		return;
	}
	_energyPoints =	(_energyPoints >= 1) ? (_energyPoints - 1) : 0;
	std::cout
		<< "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout
			<< "ClapTrap " << _name
			<< " has 0 hitpoints, IMPOSSIBLE to take more damage!"
			<< std::endl;
		return;
	}
	_hitPoints = (_hitPoints < amount) ? 0 : (_hitPoints - amount);
	std::cout
		<< "ClapTrap " << _name << " receives " << amount << " points of damage!"
		<< std::endl;
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has 0 hitpoints ... WRECKED!" << std::endl;
		return;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " has 0 hitpoints, CAN NOT be repaired!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " has 0 energy points, CAN NOT be repaired!" << std::endl;
		return;
	}
	_energyPoints =	(_energyPoints >= 1) ? (_energyPoints - 1) : 0;
	_hitPoints += amount;
	std::cout
		<< "ClapTrap " << _name << " is repaired, gained " << amount << " hit points!"
		<< std::endl;
}
