/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:28:47 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/07 23:04:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	if (N <= 0)
		return nullptr;
	Zombie *zombies = new Zombie[N];
	if (zombies != nullptr) {
		for (int i = 0; i < N; i++) {
			zombies[i].setName(name);
		}
	}
	return zombies;
}
