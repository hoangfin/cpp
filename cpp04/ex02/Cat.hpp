/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 23:17:45 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/19 15:20:51 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"
# include "Animal.hpp"

class Cat: public Animal {
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& cat);
		~Cat();

		Cat& operator=(const Cat& cat);

		void makeSound() const override;
		const Brain* getBrain() const;
};

#endif
