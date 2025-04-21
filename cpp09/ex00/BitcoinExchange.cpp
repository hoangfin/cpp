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
		_valueByDate[line.substr(0, delimPos)] = std::stof(line.substr(delimPos + 1));
	}
}

void BitcoinExchange::load(const std::string& filepath) {
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
		std::string date = line.substr(0, delimPos);
		float value = std::stof(line.substr(delimPos + 3));

		// validate date and value range in [0, 1000]
		_exchangeRateByDate[date] = value;
	}
}

void BitcoinExchange::display() const {

}
