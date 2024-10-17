/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:24:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/17 14:02:12 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main(void) {
	{
		DiamondTrap diamond("diamond");
		FragTrap frag("frag");

		diamond.attack("frag");
		frag.takeDamage(30);
		frag.beRepaired(15);
		frag.attack("diamond");
		diamond.takeDamage(30);
		diamond.beRepaired(5);

		frag.highFivesGuys();
		diamond.highFivesGuys();
		diamond.guardGate();
		diamond.whoAmI();
	}
	std::cout << std::endl;
	return 0;
}
