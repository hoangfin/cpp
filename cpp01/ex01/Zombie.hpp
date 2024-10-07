/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:13:11 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/07 22:58:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>

class Zombie {
	private:
		std::string name;

	public:
		Zombie();
		explicit Zombie(const std::string& name);
		~Zombie();
		void announce(void);
		void setName(const std::string& name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
