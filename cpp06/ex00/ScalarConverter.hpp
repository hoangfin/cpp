#pragma once

#include <string>

class ScalarConverter {
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;

		ScalarConverter& operator=(const ScalarConverter&) = delete;

		static void convert(const std::string& value);

	private:
		static void _toChar(const std::string& value);
		static void _toInt(const std::string& value);
		static void _toFloat(const std::string& value);
		static void _toDouble(const std::string& value);
};
