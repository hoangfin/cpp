#pragma once

#include <string>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& bureaucrat);

		const std::string& getName() const;
		void increaseGrade();
		void descreaseGrade();
		int getGrade() const;

	private:
		const std::string _name;
};
