#include <iostream>
#include <limits>
#include <iomanip>
#include <regex>
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& value) {
	std::regex regex(R"(^(-?[0-9]+(\.[0-9]+)?f?|.|nan|(-|\+)?inff?)$)");

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
	_toNumber(value);
	std::cout << std::endl;
}

void ScalarConverter::_toNumber(const std::string& value) {
	int iValue;
	float fValue;
	long double dValue;

	if (value.length() == 1) {
		char c = value.at(0);
		bool isDigit = (c >= '0' && c <= '9');

		iValue = static_cast<int>(isDigit ? c - 48 : c);
		fValue = static_cast<float>(isDigit ? c - 48 : c);
		dValue = static_cast<long double>(isDigit ? c - 48 : c);

		std::cout
				<< "\nint: " << iValue
				<< "\nfloat: " << std::fixed << std::setprecision(1) << fValue << "f"
				<< "\ndouble: " << std::fixed << std::setprecision(1) << dValue;
		return;
	}

	try {
		iValue = std::stoi(value);
		std::cout << "\nint: " << iValue;
	} catch(const std::exception& e) {
		std::cout << "\nint: impossible";
	}

	try {
		fValue = std::stof(value);
		std::cout << "\nfloat: " << std::fixed << std::setprecision(1) << fValue << "f";
	} catch(const std::exception& e) {
		std::cout << "\nfloat: impossible";
	}

	try {
		dValue = std::stold(value);
		std::cout << "\ndouble: " << std::fixed << std::setprecision(1) << dValue;
	} catch(const std::exception& e) {
		std::cout << "\ndouble: impossible";
	}
}

void ScalarConverter::_toChar(const std::string& value) {
	try {
		int iValue;

		if (value.length() == 1) {
			iValue = value.at(0);

			if (iValue >= '0' && iValue <= '9') {
				std::cout << "char: Non displayable";
				return;
			}
		} else {
			iValue = std::stoi(value);
		}

		if (iValue < std::numeric_limits<char>::min() || iValue > std::numeric_limits<char>::max()) {
			std::cout << "char: impossible";
			return;
		}

		if (iValue >= 32 && iValue <= 126) {
			std::cout << "char: '" << static_cast<char>(iValue) << "'";
			return;
		}

		std::cout << "char: Non displayable";
	} catch(const std::exception& e) {
		std::cout << "char: impossible";
	}
}
