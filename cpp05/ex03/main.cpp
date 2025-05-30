/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:56:32 by hoatran           #+#    #+#             */
/*   Updated: 2025/03/04 23:51:28 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void) {
	AForm* scform = nullptr;
	AForm* rrform = nullptr;
	AForm* ppform = nullptr;

	try {
		Intern intern;

		AForm* internForm = intern.makeForm("Intern", "home");
		std::cout << "internForm should be nullptr? " << (internForm == nullptr ? "yes" : "no") << "\n";

		scform = intern.makeForm("ShrubberyCreationForm", "home");
		rrform = intern.makeForm("RobotomyRequestForm", "home");
		ppform = intern.makeForm("PresidentialPardonForm", "home");
		std::cout << *scform << "\n";
		std::cout << *rrform << "\n";
		std::cout << *ppform << "\n";
		std::cout << "---\n";

		Bureaucrat david("David", 99);
		std::cout << david << "\n";
		david.signForm(*scform);
		david.signForm(*rrform);
		david.signForm(*ppform);
		david.executeForm(*scform);
		david.executeForm(*rrform);
		david.executeForm(*ppform);

		std::cout << "-------------\n";

		Bureaucrat paul("Paul", 25);
		std::cout << paul << "\n";
		paul.signForm(*scform);
		paul.signForm(*rrform);
		paul.signForm(*ppform);
		paul.executeForm(*scform);
		paul.executeForm(*rrform);
		paul.executeForm(*ppform);

		std::cout << "-------------\n";

		Bureaucrat michell("Michell", 72);
		std::cout << michell << "\n";
		michell.signForm(*scform);
		michell.signForm(*rrform);
		michell.signForm(*ppform);
		michell.executeForm(*scform);
		michell.executeForm(*rrform);
		michell.executeForm(*ppform);

		delete scform;
		delete rrform;
		delete ppform;
	} catch(const std::exception& e) {
		delete scform;
		delete rrform;
		delete ppform;
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
