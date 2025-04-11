#include <iostream>
#include <limits>
#include <iomanip>
#include <regex>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& value) {
	std::regex regex(R"(^(-?[0-9]+(\.[0-9]+)?f?|nan|(-|\+)?inff?)$)");

	if (value.length() > 1 && std::regex_match(value, regex) == false) {
		std::cout
			<< "char: impossible"
			<< "\nint: impossible"
			<< "\nfloat: impossible"
			<< "\ndouble: impossible"
			<< std::endl;
		return;
	}

	_toChar(value);
	_toInt(value);
	_toFloat(value);
	_toDouble(value);
	std::cout << std::endl;
}

void ScalarConverter::_toChar(const std::string& value) {
	if (value.length() > 1) {
		std::cout << "char: impossible";
		return;
	}

	char c = value.at(0);

	if (c < std::numeric_limits<char>::min() || c > std::numeric_limits<char>::max()) {
		std::cout << "char: impossible";
		return;
	}

	bool isDigit = (c >= '0' && c <= '9');
	bool isDisplayable = (c >= 32 && c <= 126);

	if (isDisplayable && !isDigit) {
		std::cout << "char: '" << c << "'";
		return;
	}

	std::cout << "char: Non displayable";
}

void ScalarConverter::_toInt(const std::string& value) {
	try {
		int intValue = std::stoi(value);
		std::cout << "\nint: " << intValue;
	} catch(const std::exception& e) {
		std::cout << "\nint: impossible";
	}
}

void ScalarConverter::_toFloat(const std::string& value) {
	try {
		float fValue = std::stof(value);
		std::cout << "\nfloat: " << std::fixed << std::setprecision(1) << fValue << "f";
	} catch(const std::exception& e) {
		std::cout << "\nfloat: impossible";
	}
}

void ScalarConverter::_toDouble(const std::string& value) {
	try {
		long double dValue = std::stold(value);
		std::cout << "\ndouble: " << std::fixed << std::setprecision(1) << dValue;
	} catch(const std::exception& e) {
		std::cout << "\ndouble: impossible";
	}
}
