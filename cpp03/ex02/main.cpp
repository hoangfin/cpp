/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:24:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 16:55:42 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main(void) {
	{
		FragTrap omega("Omega");
		FragTrap gamma("Gamma");

		omega.attack("Gamma");
		gamma.takeDamage(20);
		gamma.beRepaired(2);
		gamma.attack("Omega");
		omega.takeDamage(20);
		omega.beRepaired(5);
	}
	std::cout << std::endl;

	return 0;
}