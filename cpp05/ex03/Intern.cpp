#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string Intern::_forms[] = {
	"PresidentialPardonForm",
	"RobotomyRequestForm",
	"ShrubberyCreationForm"
};

Intern::Creator Intern::_creators[] = {
	[](const std::string& target) -> AForm* {
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return new PresidentialPardonForm(target);
	},

	[](const std::string& target) -> AForm* {
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return new RobotomyRequestForm(target);
	},

	[](const std::string& target) -> AForm* {
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return new ShrubberyCreationForm(target);
	}
};

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
	std::size_t size = sizeof(_forms) / sizeof(_forms[0]);

	for (std::size_t i = 0; i < size; i++) {
		if (_forms[i] == formName) {
			return _creators[i](formTarget);
		}
	}

	std::cout << "ClassNotFound: Couldn't create " << formName << " with target " << formTarget << std::endl;
	return nullptr;
}
