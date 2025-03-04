#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", false, 145, 137)
	, _target(target) {
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	AForm::execute(executor);

	std::ofstream ofstream(_target + "_shrubbery");
	std::string tree = R"(
          *
         ***
        *****
         ***
        *****
       *******
        *****
       *******
      *********
       *******
      *********
     ***********
    *************
    )";

	if (!ofstream.is_open()) {
		throw std::runtime_error("Couldn't open file " + _target + "_shrubbery");
	}

	ofstream << tree;
	ofstream.close();
	std::cout << _target << "_shrubbery has been created." << std::endl;
}