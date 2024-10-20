/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:03:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/21 00:43:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _materias[4];

	public:
		Character();
		Character(const std::string& name);
		Character(const Character& character);
		~Character();

		Character& operator=(const Character& character);

		const std::string& getName() const override;
		AMateria* getMateria(int idx) const;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;
};

#endif
