#include <iostream>
#include <limits>
#include <iomanip>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& value) {
	_toChar(value);
	_toInt(value);
	_toFloat(value);
	_toDouble(value);
}

void ScalarConverter::_toChar(const std::string& value) {
	try {
		int intValue = std::stoi(value);

		if (intValue >= std::numeric_limits<char>::min() && intValue <= std::numeric_limits<char>::max()) {
			char c = static_cast<char>(intValue);
			std::cout << "char: " << c << std::endl;
		} else {
			std::cout << "char: impossible" << std::endl;
		}
	} catch(const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
	}
}

void ScalarConverter::_toInt(const std::string& value) {
	try {
		int intValue = std::stoi(value);
		std::cout << "int: " << intValue << std::endl;
	} catch(const std::invalid_argument& e) {
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::_toFloat(const std::string& value) {
	try {
		float fValue = std::stof(value);
		std::cout << "float: " << fValue << std::endl;
	} catch(const std::invalid_argument& e) {
		std::cout << "float: impossible" << std::endl;
	}
}

void ScalarConverter::_toDouble(const std::string& value) {
	try {
		long double dValue = std::stold(value);
		std::cout << "double: " << std::fixed << std::setprecision(1) << dValue << std::endl;
	} catch(const std::invalid_argument& e) {
		std::cout << "double: impossible" << std::endl;
	}
}
