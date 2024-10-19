/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:17:27 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/19 21:15:50 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain()) {
	std::cout << "🐈 default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& cat) : Animal(cat), _brain(new Brain(*cat._brain)) {
	std::cout << "🐈 copy constructor called" << std::endl;
}

Cat::~Cat() {
	delete _brain;
	_brain = nullptr;
	std::cout << "🐈 destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& cat) {
	std::cout << "🐈 copy assignment called" << std::endl;
	if (this != &cat) {
		Animal::operator=(cat);
		*_brain = *cat._brain;
	}
	return (*this);
}

const Brain* Cat::getBrain() const {
	return _brain;
}

void Cat::makeSound() const {
	std::cout << "🐈::makesound(): meow meow" << std::endl;
}
