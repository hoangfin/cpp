/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:24:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 13:57:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	{
		ClapTrap alpha("Alpha");
		ClapTrap beta("Beta");

		alpha.attack("Beta");
		beta.takeDamage(5);
		beta.beRepaired(2);
		beta.attack("Alpha");
		alpha.takeDamage(3);
		alpha.beRepaired(1);
	}
	std::cout << std::endl;
	{
		ClapTrap alpha("Alpha");
		ClapTrap beta("Beta");

		for (int i = 0; i < 10; i++) {
			alpha.attack("Beta");
			beta.takeDamage(1);
		}
		beta.attack("Alpha");
	}
	return 0;
}