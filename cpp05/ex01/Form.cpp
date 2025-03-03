#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

static int validateGrade(int grade, const std::string& gradeType) {
	if (grade < 1) {
		throw Form::GradeTooHighException("Invalid Argument: " + gradeType + " is too high");
	}

	if (grade > 150) {
		throw Form::GradeTooLowException("Invalid Argument: " + gradeType + " is too low");
	}

	return grade;
}

Form::GradeTooHighException::GradeTooHighException(const std::string& message) : _message(message) {}

const char* Form::GradeTooHighException::what() const noexcept {
	return _message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message) : _message(message) {}

const char* Form::GradeTooLowException::what() const noexcept {
	return _message.c_str();
}

Form::Form(const std::string& name, bool isSigned, int signGrade, int executionGrade)
	: _name(name)
	, _isSigned(isSigned)
	, _signGrade(validateGrade(signGrade, "signGrade"))
	, _executionGrade(validateGrade(executionGrade, "executionGrade")) {
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade) {
		_isSigned = true;
	} else {
		_isSigned = false;
	}

	bureaucrat.signForm(*this);
}

const std::string& Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecutionGrade() const {
	return _executionGrade;
}

bool Form::isSigned() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os	<< form.getName() << "["
		<< "isSigned=" << (form.isSigned() ? "true" : "false")
		<< ", signGrade=" << form.getSignGrade()
		<< ", executionGrade=" << form.getExecutionGrade() << "]";
	return os;
}
