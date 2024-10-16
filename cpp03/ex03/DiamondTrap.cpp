/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:14:39 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 23:57:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name")
	, ScavTrap(name)
	, FragTrap(name)
	, _name(name) {
	_energyPoints = 50;
	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
	: ClapTrap(diamondTrap)
	, ScavTrap(diamondTrap)
	, FragTrap(diamondTrap) {
	std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
	std::cout << "DiamondTrap copy assignment invoked." << std::endl;
	if (this != &diamondTrap) {
		ScavTrap::operator=(diamondTrap);
		FragTrap::operator=(diamondTrap);
		this->_name = diamondTrap._name;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << _name << ", ClapTrap " << ClapTrap::_name << std::endl;
}
