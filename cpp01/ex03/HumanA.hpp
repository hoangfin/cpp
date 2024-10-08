/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:18:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/08 23:53:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon& _weapon;

	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();
		void attack();
};

#endif
