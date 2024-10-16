/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:50:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 23:59:32 by hoatran          ###   ########.fr       */
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
	std::cout << "ClapTrap copy assignment invoked." << std::endl;
	if (this != &clapTrap) {
		_name = clapTrap._name;
		_hitPoints = clapTrap._hitPoints;
		_energyPoints = clapTrap._energyPoints;
		_attackDamage = clapTrap._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is disabled, CAN NOT attack!" << std::endl;
		return;
	}
	_energyPoints =	(_energyPoints >= 1) ? (_energyPoints - 1) : 0;
	std::cout
		<< "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints = (_hitPoints < amount) ? 0 : (_hitPoints - amount);
	std::cout << "ClapTrap " << _name << " receives " << amount << " points of damage!" << std::endl;
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " has 0 hit points ... disabled!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is disabled, CAN NOT be repaired!" << std::endl;
		return;
	}
	_energyPoints =	(_energyPoints >= 1) ? (_energyPoints - 1) : 0;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repaired, gained " << amount << " hit points!" << std::endl;
}
