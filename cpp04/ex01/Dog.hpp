/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:01:34 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/19 15:21:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class Dog: public Animal {
	private:
		Brain* _brain;

	public:
		Dog();
		Dog(const Dog& dog);
		~Dog();

		Dog& operator=(const Dog& dog);

		const Brain* getBrain() const;
		void makeSound() const override;
};

#endif
