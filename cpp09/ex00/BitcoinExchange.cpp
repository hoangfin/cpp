#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <iomanip>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream ifs("data.csv");

	if (!ifs) {
		throw std::runtime_error("Couldn't load database file");
	}

	std::string line;

	std::getline(ifs, line);

	while (std::getline(ifs, line) && !line.empty()) {
		std::size_t delimPos = line.find(',');
		_exchangeRateByDate[line.substr(0, delimPos)] = std::stof(line.substr(delimPos + 1));
	}

	std::cout
		<< "First date: " << _exchangeRateByDate.begin()->first
		<< ", exchangeRate: " << _exchangeRateByDate.begin()->second
		<< "\nLast date: " << std::prev(_exchangeRateByDate.end())->first
		<< ", exchangeRate: " << std::prev(_exchangeRateByDate.end())->second
		<< std::endl;
}

void BitcoinExchange::display(const std::string& filepath) {
	std::ifstream ifs(filepath);
	std::string line;
	std::regex entryRegex(R"(^\d{4}-\d{2}-\d{2} \| \d+(\.\d+)?$)");

	if (!ifs) {
		throw std::runtime_error("Couldn't open " + filepath);
	}

	std::getline(ifs, line);

	while (std::getline(ifs, line) && !line.empty()) {
		if (!std::regex_match(line, entryRegex)) {
			throw std::runtime_error("Invalid entry: " + line);
		}

		std::size_t delimPos = line.find(" | ");

		if (delimPos == std::string::npos) {
			std::cerr << "Error: bad input => Couldn't find |" << std::endl;
			continue;
		}

		std::string date = line.substr(0, delimPos);

		if (!_isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		float value = std::stof(line.substr(delimPos + 3));
		(void)value;
		// validate date and value range in [0, 1000]
		float exchangeRate = _getExchangeRate(date);

		if (exchangeRate == -1.0) {
			std::cerr << date << " => Couldn't find this date in database" << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << (value * exchangeRate) << std::endl;
	}
}

float BitcoinExchange::_getExchangeRate(const std::string& date) const {
	auto it = _exchangeRateByDate.lower_bound(date);

	if (it == _exchangeRateByDate.end()) {
		return std::prev(it)->second;
	}

	if (it->first == date) {
		return it->second;
	}

	if (it == _exchangeRateByDate.begin()) {
		return (-1);
	}

	return std::prev(it)->second;
}

bool BitcoinExchange::_isValidDate(const std::string& date) {
	int year, month, day;
    char delim1, delim2;
    std::istringstream iss(date);
    if (!(iss >> year >> delim1 >> month >> delim2 >> day) || delim1 != '-' || delim2 != '-') {
        return false;
    }

    // Validate year, month, and day ranges
    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Check the number of days in the given month
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = daysInMonth[month - 1];

    // Handle leap years for February
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        maxDay = 29;
    }

    // Check if the day is within the allowed range
    return day <= maxDay;
}
