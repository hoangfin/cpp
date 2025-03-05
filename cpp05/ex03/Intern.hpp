#pragma once

#include <string>
#include <functional>
#include "AForm.hpp"

class Intern {
	public:
		Intern() = default;
		Intern(const Intern&) = default;
		~Intern() = default;

		Intern& operator=(const Intern&) = default;

		AForm* makeForm(const std::string& formName, const std::string& formTarget);

	private:
		static const std::string _forms[];
		static std::function<AForm*(const std::string&)> _creators[];
};
