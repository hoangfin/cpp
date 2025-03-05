#pragma once

#include <string>

class Bureaucrat;

class AForm {
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

		AForm() = delete;
		AForm(const std::string& name, bool isSigned, int signGrade, int executionGrade);
		virtual ~AForm() = default;

		AForm& operator=(const AForm&) = delete;

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& executor) const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& form);
