/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:32:49 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 01:48:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>

class ICharacter;

class AMateria {
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& amateria);
		virtual ~AMateria();

		AMateria& operator=(const AMateria& materia);
		const std::string& getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
