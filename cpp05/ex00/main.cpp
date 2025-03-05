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
