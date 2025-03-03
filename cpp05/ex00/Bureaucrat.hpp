#pragma once

#include <string>

class Bureaucrat {
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

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other) = default;
		~Bureaucrat() = default;

		Bureaucrat& operator=(const Bureaucrat& other) = delete;

		void increaseGrade();
		void descreaseGrade();

		const std::string& getName() const;
		int getGrade() const;

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
