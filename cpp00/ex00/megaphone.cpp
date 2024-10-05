/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:55:27 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/05 23:41:35 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char **argv) {
	if (argc <= 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	argv += 1;
	for (int i = 0; argv[i] != NULL; i++) {
		std::string arg = argv[i];
		for (char& c : arg) {
			c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
		}
		std::cout << arg;
	}
	std::cout << std::endl;
	return 0;
}
