/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:35:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/11 20:40:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) :_name(name) {}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon == nullptr)
		std::cout << _name << " attacks with their null" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}