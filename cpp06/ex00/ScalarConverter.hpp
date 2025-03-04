#pragma once

#include <string>

class ScalarConverter {
	public:
		ScalarConverter() = default;
		ScalarConverter(const ScalarConverter&) = default;
		~ScalarConverter() = default;

		ScalarConverter& operator=(const ScalarConverter&) = default;
		
		static void convert(const std::string& value);
};
