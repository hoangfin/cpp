/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:38:50 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/16 16:54:48 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ScavTrap.hpp"

class FragTrap: public ScavTrap {
	public:
		FragTrap() = delete;
		explicit FragTrap(std::string name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap();

		FragTrap& operator=(const FragTrap& fragTrap);

		void attack(const std::string& target) override;
		void highFivesGuys(void);
};

#endif
