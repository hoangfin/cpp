#include <iostream>
#include <limits>
#include <iomanip>
#include <regex>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& value) {
	if (value.length() == 1) {
		char c = value.at(0);
		bool isDisplayable = (c >= 32 && c <= 126) && !(c >= '0' && c <= '9');
		std::cout
			<< "char: " << (isDisplayable ? std::string(1, c) : "Non displayable")
			<< "\nint: " << static_cast<int>(c)
			<< "\nfloat: " << static_cast<float>(c)
			<< "\ndouble: " << static_cast<double>(c)
			<< std::endl;
		return;
	}

	std::regex regex(R"(^(-?[0-9]+(\.[0-9]+)?f?|nan|(-|\+)?inff?)$)");

	if (!std::regex_match(value, regex)) {
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
	try {
		int intValue = std::stoi(value);

		if (intValue < std::numeric_limits<char>::min() || intValue > std::numeric_limits<char>::max()) {
			throw std::out_of_range("Out of char range");
		}

		char c = static_cast<char>(intValue);
		std::cout << "char: '" << c << "'";
	} catch(const std::exception& e) {
		std::cout << "char: impossible";
	}
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
