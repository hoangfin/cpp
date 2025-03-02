/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:56:32 by hoatran           #+#    #+#             */
/*   Updated: 2025/03/03 01:53:07 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main(void) {
	try {
		Bureaucrat david("David", 3);
		std::cout << david << std::endl;

		david.increaseGrade();
		std::cout << "increaseGrade(): " << david << std::endl;

		david.increaseGrade();
		std::cout << "increaseGrade(): " << david << std::endl;

		david.increaseGrade();
		std::cout << "increaseGrade(): " << david << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat jane("Jane", 148);
		std::cout << jane << std::endl;

		jane.descreaseGrade();
		std::cout << "descreaseGrade(): " << jane << std::endl;

		jane.descreaseGrade();
		std::cout << "descreaseGrade(): " << jane << std::endl;

		jane.descreaseGrade();
		std::cout << "descreaseGrade(): " << jane << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
