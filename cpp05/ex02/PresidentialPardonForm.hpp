#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm() = delete;
		explicit PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other) = default;
		~PresidentialPardonForm() = default;

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other) = delete;

		void execute(const Bureaucrat& executor) const override;

	private:
		std::string _target;
};
