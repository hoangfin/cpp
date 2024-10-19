/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:21:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/19 23:21:20 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

void testDeepCopy() {
	Dog bulldog;
	Dog poodle(bulldog);
	Cat ragdoll;
	Cat birman(ragdoll);

	std::cout << "TEST DEEP COPY\n";
	if (
		bulldog.getBrain() == poodle.getBrain()
		|| bulldog.getBrain()->getIdeas() == poodle.getBrain()->getIdeas()
	) {
		std::cout << "Shallow copy, failed 👎" << std::endl;
		return;
	}
	std::cout << "Deep copy 👍" << std::endl;
}

int main(void) {
	{
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		delete dog;
		delete cat;
	}
	testDeepCopy();
	{
		Animal** dogs = new Animal*[5];
		Animal** cats = new Animal*[5];

		for (int i = 0; i < 5; i++) {
			std::cout << "--------------------\n";
			dogs[i] = new Dog();
			std::cout << "\n";
			cats[i] = new Cat();
		}

		for (int i = 0; i < 5; i++) {
			std::cout << "--------------------\n";
			delete dogs[i];
			std::cout << "\n";
			delete cats[i];
		}
		std::cout.flush();
		delete[] dogs;
		delete[] cats;
	}
	return 0;
}
