/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:56:32 by hoatran           #+#    #+#             */
/*   Updated: 2025/03/04 19:09:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	try {
		Bureaucrat david("David", 99);
		ShrubberyCreationForm scform("home");
		RobotomyRequestForm rrform("home");
		PresidentialPardonForm ppform("home");

		std::cout << david << "\n";
		std::cout << scform << "\n";
		std::cout << rrform << "\n";
		std::cout << ppform << "\n";
		std::cout << "---\n";
		david.signForm(scform);
		david.signForm(rrform);
		david.signForm(ppform);

		david.executeForm(scform);
		david.executeForm(rrform);
		david.executeForm(ppform);

		// david.increaseGrade();
		// std::cout << "Increase grade by 1 -> " << david << std::endl;
		// david.signForm(form);

		// david.increaseGrade();
		// std::cout << "Increase grade by 1 -> " << david << std::endl;
		// david.signForm(form);

		// david.increaseGrade();
		// std::cout << "Increase grade by 1 -> " << david << std::endl;
		// david.signForm(form);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "==========================================\n";

	return 0;
}
