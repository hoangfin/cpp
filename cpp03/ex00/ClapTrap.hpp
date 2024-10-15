/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:49:39 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 00:21:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
	private:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		explicit ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& clapTrap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif