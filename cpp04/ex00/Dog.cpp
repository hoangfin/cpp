/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:05:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/17 23:36:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "🐕 default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& dog) : Animal(dog) {
	std::cout << "🐕 copy constructor called" << std::endl;
	_type = dog._type;
}

Dog::~Dog() {
	std::cout << "🐕 destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) {
	std::cout << "🐕 copy assignment called" << std::endl;
	if (this != &dog) {
		Animal::operator=(dog);
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "🐕::makesound(): woof woof" << std::endl;
}