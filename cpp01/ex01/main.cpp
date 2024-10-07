/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:29:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/07 23:08:33 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie foo = Zombie("Foo");
	foo.announce();

	Zombie *zombies = zombieHorde(12, "Horde");
	for (int i = 0; i < 12; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}
