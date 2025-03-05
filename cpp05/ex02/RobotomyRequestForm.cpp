#include <iostream>
#include <random>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", false, 72, 45)
	, _target(target) {
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	std::cout << "Bruuuuuhhhhhhzzzzzzzzzzz .....\n";

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	int result = dist(gen);

	std::cout
		<< _target
		<< (result ? " has been robotomized successfully" : " has failed robotomization")
		<< std::endl;
}
