#pragma once

#include <map>
#include <optional>

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
		std::optional<float> _getExchangeRate(const std::string& date) const;
		static std::string _getDate(const std::string& date);
		static float _getValue(const std::string& date);
};
