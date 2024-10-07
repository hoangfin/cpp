/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:29:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/07 22:48:37 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie foo = Zombie("Foo");
	foo.announce();

	Zombie *baz = newZombie("Baz");
	baz->announce();
	delete baz;

	randomChump("RandomZombie");
	return 0;
}
