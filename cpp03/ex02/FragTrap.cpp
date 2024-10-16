/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:44:45 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 16:55:21 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ScavTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created" << std::endl;
}
FragTrap::FragTrap(const FragTrap& fragTrap) : ScavTrap(fragTrap) {
	std::cout << "FragTrap " << _name << " created" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
	if (this != &fragTrap) {
		ScavTrap::operator=(fragTrap);
	}
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout << "FragTrap " << _name << " is disabled, CAN NOT attack!" << std::endl;
		return;
	}
	_energyPoints =	(_energyPoints >= 1) ? (_energyPoints - 1) : 0;
	std::cout
		<< "FragTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << ", High Five Guys!!" << std::endl;
}
