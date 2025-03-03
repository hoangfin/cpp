#pragma once

#include <string>

class Bureaucrat;

class Form {
	public:
		class GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(const std::string& message);
				const char* what() const noexcept override;

			private:
				std::string _message;
		};

		class GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(const std::string& message);
				const char* what() const noexcept override;

			private:
				std::string _message;
		};

		Form() = delete;
		Form(const std::string& name, bool isSigned, int signGrade, int executionGrade);
		~Form() = default;

		Form& operator=(const Form&) = delete;

		void beSigned(const Bureaucrat& bureaucrat);

		const std::string& getName() const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecutionGrade() const;

	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _executionGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& form);
