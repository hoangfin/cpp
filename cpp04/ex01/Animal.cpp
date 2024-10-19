/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 20:43:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/18 00:12:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& animal) : _type(animal._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& animal) {
	std::cout << "Animal copy assignment called" << std::endl;
	if (this != &animal) {
		this->_type = animal._type;
	}
	return (*this);
}

const std::string& Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "Animal::makeSound(): prrraawww... " << std::endl;
}