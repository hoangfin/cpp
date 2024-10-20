/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:58:51 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 21:34:41 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _amaterias[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& ms);
		void learnMateria(AMateria*) override;
		AMateria* createMateria(const std::string& type) override;
};

#endif
