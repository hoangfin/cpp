#pragma once

#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&) = default;
		~BitcoinExchange() = default;

		BitcoinExchange& operator=(const BitcoinExchange&) = default;

		void load(const std::string& filepath);
		void display() const;

	private:
		std::map<std::string, float> _valueByDate;
		std::map<std::string, float> _exchangeRateByDate;
};
