/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 22:57:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/08 23:37:51 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
	return _type;
}

void Weapon::setType(const std::string& type) {
	_type = type;
}
