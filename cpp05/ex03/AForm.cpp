#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

static int validateGrade(int grade, const std::string& gradeType) {
	if (grade < 1) {
		throw AForm::GradeTooHighException("Invalid Argument: " + gradeType + " is too high");
	}

	if (grade > 150) {
		throw AForm::GradeTooLowException("Invalid Argument: " + gradeType + " is too low");
	}

	return grade;
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& message) : _message(message) {}

const char* AForm::GradeTooHighException::what() const noexcept {
	return _message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message) : _message(message) {}

const char* AForm::GradeTooLowException::what() const noexcept {
	return _message.c_str();
}

AForm::AForm(const std::string& name, bool isSigned, int signGrade, int executionGrade)
	: _name(name)
	, _isSigned(isSigned)
	, _signGrade(validateGrade(signGrade, "signGrade"))
	, _executionGrade(validateGrade(executionGrade, "executionGrade")) {
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException(
			"Bureaucrat " + bureaucrat.getName()
			+ " couldn't sign " + _name + " because of low grade");
	}

	_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!AForm::isSigned()) {
		throw std::runtime_error(
			AForm::getName()
			+ " has not yet been signed by bureaucrat "
			+ executor.getName()
		);
	}

	if (executor.getGrade() > AForm::getExecutionGrade()) {
		throw GradeTooLowException(
			"Bureaucrat "
			+ executor.getName()
			+ " does not have sufficient grade to execute "
			+ AForm::getName()
		);
	}
}

const std::string& AForm::getName() const {
	return _name;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecutionGrade() const {
	return _executionGrade;
}

bool AForm::isSigned() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os	<< form.getName() << ", "
		<< "status: " << (form.isSigned() ? "signed" : "unsigned")
		<< " | sign grade: " << form.getSignGrade()
		<< " | execution grade: " << form.getExecutionGrade();
	return os;
}
