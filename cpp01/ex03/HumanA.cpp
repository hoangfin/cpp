/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:26:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/08 23:53:26 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(
	const std::string& name,
	Weapon& weapon
)
	: _name(name)
	, _weapon(weapon) {
}

HumanA::~HumanA() {

}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
