/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:00:36 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/18 23:02:42 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& cat) : WrongAnimal(cat) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	_type = cat._type;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& cat) {
	std::cout << "WrongCat copy assignment called" << std::endl;
	if (this != &cat) {
		WrongAnimal::operator=(cat);
	}
	return (*this);
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat::makesound(): meow meow" << std::endl;
}
