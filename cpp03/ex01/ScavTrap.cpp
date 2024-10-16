/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:25:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 16:26:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap) {
	std::cout << "ScavTrap " << _name << " created" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
	if (this != &scavTrap) {
		ClapTrap::operator=(scavTrap);
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " is disabled, CAN NOT attack!" << std::endl;
		return;
	}
	_energyPoints =	(_energyPoints >= 1) ? (_energyPoints - 1) : 0;
	std::cout
		<< "ScavTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout <<  "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
