/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:56:32 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/21 00:55:01 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void) {
	IMateriaSource* src = new MateriaSource();
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

	AMateria* amaterias[4];
	amaterias[0] = src->createMateria("ice");
	amaterias[1] = src->createMateria("cure");
	amaterias[2] = src->createMateria("ice");
	amaterias[3] = src->createMateria("cure");

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	me->equip(amaterias[0]);
	me->equip(amaterias[1]);
	me->use(0, *bob);
	me->use(1, *bob);

	for (int i = 0; i < 4; i++) {
		delete amaterias[i];
	}
	delete bob;
	delete me;
	delete src;
	return 0;
}
