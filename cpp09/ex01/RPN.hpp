#pragma once

#include <string>
#include <stack>

class RPN {
	public:
		RPN() = delete;
		RPN(const RPN&) = delete;
		~RPN() = delete;

		RPN& operator=(const RPN&) = delete;
		static void calculate(const std::string& rpn);

	private:
		static constexpr bool _isRpnToken(const char token);
		static void _handleCalculation(std::stack<long long>& stack, const char charToken);
		static constexpr long long _add(long long a, long long b);
		static constexpr long long _subtract(long long a, long long b);
		static constexpr long long _multiply(long long a, long long b);
		static constexpr long long _divide(long long a, long long b);
};