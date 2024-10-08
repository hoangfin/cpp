/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:29:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/08 21:30:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The memory address of the str=" << &str << "\n";
	std::cout << "The memory address held by stringPTR=" << stringPTR << "\n";
	std::cout << "The memory address held by stringREF=" << &stringREF << "\n";

	std::cout << "The value of the str=" << str << "\n";
	std::cout << "The value pointed to by stringPTR=" << *stringPTR << "\n";
	std::cout << "The value pointed to by stringREF=" << stringREF << std::endl;
	return 0;
}
