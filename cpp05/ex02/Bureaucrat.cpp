#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message) : _message(message) {}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return _message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message) : _message(message) {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return _message.c_str();
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1) {
		throw GradeTooHighException("Invalid Argument: grade is too high");
	}

	if (grade > 150) {
		throw GradeTooLowException("Invalid Argument: grade is too low");
	}

	_grade = grade;
}

void Bureaucrat::increaseGrade() {
	if (_grade - 1 < 1) {
		throw GradeTooHighException("Invalid Argument: grade is too high");
	}

	_grade -= 1;
}

void Bureaucrat::descreaseGrade() {
	if (_grade + 1 > 150) {
		throw GradeTooLowException("Invalid Argument: grade is too low");
	}

	_grade += 1;
}

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
