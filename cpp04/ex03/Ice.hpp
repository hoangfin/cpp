/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:16:25 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/20 01:17:47 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria {
	public:
		Ice();
		Ice(const Ice& ice);
		~Ice();

		Ice& operator=(const Ice& ice);
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif
