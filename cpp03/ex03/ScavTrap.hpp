/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:16:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 18:29:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap() = delete;
		explicit ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scavTrap);
		virtual ~ScavTrap();

		ScavTrap& operator=(const ScavTrap& scavTrap);

		void attack(const std::string& target) override;
		void guardGate();
};

#endif
