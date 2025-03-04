#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm() = delete;
		explicit RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm&) = default;
		~RobotomyRequestForm() = default;

		RobotomyRequestForm& operator=(const RobotomyRequestForm&) = delete;

		void execute(const Bureaucrat& executor) const override;

	private:
		std::string _target;
};
