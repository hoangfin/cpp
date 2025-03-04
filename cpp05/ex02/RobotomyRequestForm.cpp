#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", false, 72, 45)
	, _target(target) {
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);
	std::cout
		<< "Bruuuuuhhhhhhzzzzzzzzzzz .....\n"
		<< _target << R"( has been robotomized successfully 50% of the time)"
		<< std::endl;
}
