/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:08:43 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 23:54:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	private:
		std::string _name;

	public:
		DiamondTrap() = delete;
		explicit DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& diamondTrap);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& diamondTrap);

		void attack(const std::string& target) override;
		void whoAmI();
};

#endif
