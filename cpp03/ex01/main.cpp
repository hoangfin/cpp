/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:24:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/17 13:48:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void) {
	{
		ScavTrap omega("Omega");
		ScavTrap gamma("Gamma");

		omega.attack("Gamma");
		gamma.takeDamage(20);
		gamma.beRepaired(2);
		gamma.attack("Omega");
		omega.takeDamage(20);
		omega.beRepaired(5);
		omega.guardGate();
		gamma.guardGate();
	}
	std::cout << std::endl;

	return 0;
}
