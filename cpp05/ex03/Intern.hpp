#pragma once

#include <string>
#include "AForm.hpp"

class Intern {
	public:
		Intern() = default;
		Intern(const Intern&) = default;
		~Intern() = default;

		Intern& operator=(const Intern&) = default;

		AForm* makeForm(const std::string& formName, const std::string& formTarget);

	private:
		typedef AForm* (*Creator)(const std::string&);

		static const std::string _forms[];
		static Creator _creators[];
};