/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:22:45 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/08 23:59:30 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;

	public:
		HumanB(const std::string& name);
		~HumanB();
		void setWeapon(Weapon& weapon);
		void attack();
};

#endif
