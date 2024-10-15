/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 23:24:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 00:07:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void) {
	ClapTrap react("React");
	ClapTrap vue("Vue");
	ClapTrap svelte("Svelte");

	std::cout << "=======================" << std::endl;
	react.attack("Vue");
	vue.takeDamage(1);

	svelte.attack("Vue");
	vue.takeDamage(3);

	vue.beRepaired(2);

	react.attack("Svelte");
	svelte.takeDamage(10);
	svelte.attack("React");
	react.takeDamage(0);

	std::cout << "=======================" << std::endl;
	return 0;
}