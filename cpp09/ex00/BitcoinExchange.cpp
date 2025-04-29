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
			std::cerr << "Error: bad input => " << std::endl;
			continue;
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

		float value;

		try {
			value = std::stof(line.substr(delimPos + 3));

			if (value < 0.0 || value > 1000.0) {
				throw std::runtime_error(std::to_string(value) + " is out of bounds [0, 1000]");
			}
		} catch(const std::exception& e) {
			std::cerr << "Error: bad input => " << e.what() << std::endl;
			continue;
		}

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

bool BitcoinExchange::_isValidDate(const std::string& date) {
	int year, month, day;
    char delim;
    std::istringstream iss(date);

    if (!(iss >> year >> delim >> month >> delim >> day)) {
        return false;
    }

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDay = daysInMonth[month - 1];

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        maxDay = 29;
    }

    return day <= maxDay;
}
