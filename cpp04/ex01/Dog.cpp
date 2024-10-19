/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:05:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/19 21:15:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
	std::cout << "🐕 default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& dog) : Animal(dog), _brain(new Brain(*dog._brain)) {
	std::cout << "🐕 copy constructor called" << std::endl;
}

Dog::~Dog() {
	delete _brain;
	_brain = nullptr;
	std::cout << "🐕 destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog) {
	std::cout << "🐕 copy assignment called" << std::endl;
	if (this != &dog) {
		Animal::operator=(dog);
		*_brain = *dog._brain;
	}
	return (*this);
}

const Brain* Dog::getBrain() const {
	return _brain;
}

void Dog::makeSound() const {
	std::cout << "🐕::makesound(): woof woof" << std::endl;
}
