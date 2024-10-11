/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:29:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/11 15:31:20 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;

	if (argc != 2) {
		std::cerr << "Program requires exactly one argument: level" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}
