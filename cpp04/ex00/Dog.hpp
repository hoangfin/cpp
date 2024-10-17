/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:01:34 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/17 23:29:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {

	public:
		Dog();
		Dog(const Dog& dog);
		~Dog();

		Dog& operator=(const Dog& dog);

		void makeSound() const override;
};

#endif
