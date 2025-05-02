#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
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
}

void BitcoinExchange::display(const std::string& filepath) {
	std::ifstream ifs(filepath);
	std::string line;

	if (!ifs) {
		throw std::runtime_error("Couldn't open " + filepath);
	}

	std::getline(ifs, line);

	while (std::getline(ifs, line) && !line.empty()) {
		std::string date = _getDate(line);

		if (date.empty()) { continue; }

		std::size_t delimPos = line.find(" | ");

		if (delimPos == std::string::npos) {
			std::cerr << "Error: bad input => ' | ' not found" << std::endl;
			continue;
		}

		float value = _getValue(line.substr(delimPos + 3));

		if (value < 0.0f) { continue; }

		auto exchangeRate = _getExchangeRate(date);

		if (!exchangeRate.has_value()) {
			std::cerr << date << " => Couldn't find this date in database" << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << (value * exchangeRate.value()) << std::endl;
	}
}

std::optional<float> BitcoinExchange::_getExchangeRate(const std::string& date) const {
	auto it = _exchangeRateByDate.lower_bound(date);

	if (it == _exchangeRateByDate.end()) {
		return std::prev(it)->second;
	}

	if (it->first == date) {
		return it->second;
	}

	if (it == _exchangeRateByDate.begin()) {
		return std::nullopt;
	}

	return std::prev(it)->second;
}

std::string BitcoinExchange::_getDate(const std::string& date) {
	int year, month, day;
    char delim, delim2;
    std::istringstream iss(date);

	if (!(iss >> year >> delim >> month >> delim2 >> day)) {
		std::cerr << "Error: bad input => " << date << std::endl;
        return "";
    }

    if (year < 2009 || delim != '-' || delim2 != '-' || month < 1 || month > 12 || day < 1 || day > 31) {
		std::cerr << "Error: bad input => " << date << std::endl;
        return "";
    }

    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = daysInMonth[month - 1];

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        maxDay = 29;
    }

	if (day > maxDay) {
		std::cerr << "Error: bad input => " << date << std::endl;
        return "";
	}

	std::ostringstream oss;
	oss << year << delim
		<< (month < 10 ? "0" : "") << month << delim
		<< (day < 10 ? "0" : "") << day;
    return oss.str();
}

float BitcoinExchange::_getValue(const std::string& value) {
	float fValue;
	std::istringstream iss(value);

	if (!(iss >> fValue) || !(iss >> std::ws).eof()) {
		std::cerr << "Error: bad input => " << value << std::endl;
		return -1.0f;
	}

	if (fValue < 0.0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return -1.0f;
	}

	if (fValue > 1000.0f) {
		std::cerr << "Error: too large a number." << std::endl;
		return -1.0f;
	}

	return fValue;
}