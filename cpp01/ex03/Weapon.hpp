/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:35:50 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/08 23:46:49 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon();
		explicit Weapon(const std::string& type);
		~Weapon();
		const std::string& getType() const;
		void setType(const std::string& type);
};

#endif
