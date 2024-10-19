/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:09:49 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 01:17:38 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria {
	public:
		Cure();
		Cure(const Cure& cure);
		~Cure();

		Cure& operator=(const Cure& cure);
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif
