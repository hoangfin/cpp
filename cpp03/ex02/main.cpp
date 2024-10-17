/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:24:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/17 13:52:59 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main(void) {
	{
		FragTrap foo("foo");
		FragTrap baz("baz");

		foo.attack("baz");
		baz.takeDamage(30);
		baz.beRepaired(2);
		baz.attack("foo");
		foo.takeDamage(30);
		foo.beRepaired(5);

		foo.highFivesGuys();
		baz.highFivesGuys();
	}
	std::cout << std::endl;

	return 0;
}
