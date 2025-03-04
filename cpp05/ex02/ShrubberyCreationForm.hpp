#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm() = delete;
		explicit ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm&) = default;
		~ShrubberyCreationForm() = default;

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&) = delete;

		void execute(const Bureaucrat& executor) const override;

	private:
		std::string _target;
};
