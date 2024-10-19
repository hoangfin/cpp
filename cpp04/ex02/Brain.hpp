/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:47:27 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/19 15:00:13 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {
	private:
		std::string* _ideas;

	public:
		Brain();
		Brain(const Brain& brain);
		~Brain();
		Brain& operator=(const Brain& brain);
		const std::string* getIdeas() const;
};

#endif
