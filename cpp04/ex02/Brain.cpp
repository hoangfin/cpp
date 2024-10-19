/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:54:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/19 21:16:59 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain() : _ideas(new std::string[100]) {
	std::cout << "🧠 constructor called" << std::endl;
}

Brain::Brain(const Brain& brain) : _ideas(new std::string[100]) {
	std::cout << "🧠 copy constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain() {
	std::cout << "🧠 destructor called" << std::endl;
	delete[] _ideas;
	_ideas = nullptr;
}

Brain& Brain::operator=(const Brain& brain) {
	std::cout << "🧠 copy assignment called" << std::endl;
	if (this != &brain) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = brain._ideas[i];
		}
	}
	return (*this);
}

const std::string* Brain::getIdeas() const {
	return _ideas;
}
