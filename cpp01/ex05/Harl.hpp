/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:50:40 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/10 15:47:52 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl {
	private:
		typedef void (Harl::*Callable)();
		void debug();
		void info();
		void warning();
		void error();

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
