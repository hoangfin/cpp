/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:56:32 by hoatran           #+#    #+#             */
/*   Updated: 2025/03/03 23:40:47 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		Bureaucrat david("David", 3);
		Form form("Internship", false, 2, 1);

		std::cout << david << "\n";
		std::cout << form << "\n";
		std::cout << "---\n";
		david.signForm(form);

		david.increaseGrade();
		std::cout << "Increase grade by 1 -> " << david << std::endl;
		david.signForm(form);

		david.increaseGrade();
		std::cout << "Increase grade by 1 -> " << david << std::endl;
		david.signForm(form);

		david.increaseGrade();
		std::cout << "Increase grade by 1 -> " << david << std::endl;
		david.signForm(form);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "==========================================\n";

	try {
		Bureaucrat jane("Jane", 148);
		Form form("exchange-student-form", false, 149, 1);

		std::cout << jane << "\n";
		std::cout << form << "\n";
		std::cout << "---\n";
		jane.signForm(form);

		jane.descreaseGrade();
		std::cout << "Descrease grade by 1 -> " << jane << std::endl;
		jane.signForm(form);

		jane.descreaseGrade();
		std::cout << "Descrease grade by 1 -> " << jane << std::endl;
		jane.signForm(form);

		jane.descreaseGrade();
		std::cout << "Descrease grade by 1 -> " << jane << std::endl;
		jane.signForm(form);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
