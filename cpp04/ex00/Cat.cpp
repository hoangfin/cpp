/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:17:27 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/17 23:35:50 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "🐈 default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& cat) : Animal(cat) {
	std::cout << "🐈 copy constructor called" << std::endl;
	_type = cat._type;
}

Cat::~Cat() {
	std::cout << "🐈 destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "🐈 copy assignment called" << std::endl;
	if (this != &cat) {
		Animal::operator=(cat);
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "🐈::makesound(): meow meow" << std::endl;
}