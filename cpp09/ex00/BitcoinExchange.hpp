#pragma once

#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&) = default;
		~BitcoinExchange() = default;

		BitcoinExchange& operator=(const BitcoinExchange&) = default;

		void display(const std::string& filepath);

	private:
		std::map<std::string, float> _valueByDate;
		std::map<std::string, float> _exchangeRateByDate;
		float _getExchangeRate(const std::string& date) const;
		static bool _isValidDate(const std::string& date);
};
