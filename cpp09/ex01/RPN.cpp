#include <iostream>
#include <sstream>
#include <limits>
#include "RPN.hpp"

constexpr bool RPN::_isRpnToken(const char token) {
	return (
		(token >= '0' && token <= '9')
		|| token == '+' || token == '-'
		|| token == '*' || token == '/'
	);
}

constexpr long long RPN::_add(long long a, long long b) {
	if (b > 0 && (a > std::numeric_limits<long long>::max() - b)) {
		throw std::runtime_error("Error: Overflow occurred");
	}

	return a + b;
}

constexpr long long RPN::_subtract(long long a, long long b) {
	if (a < 0) {
		if (a < std::numeric_limits<long long>::min() + b) {
			throw std::runtime_error("Error: Underflow occurred");
		}
	}

	if (b < 0) {
		if (a > std::numeric_limits<long long>::max() + b) {
			throw std::runtime_error("Error: Overflow occurred");
		}
	}

	return a - b;
}

constexpr long long RPN::_multiply(long long a, long long b) {
	if (a < 0 || b < 0) {
		if (a < std::numeric_limits<long long>::min() / b) {
			throw std::runtime_error("Error: Underflow occurred");
		}

		return a * b;
	}

	if (a > std::numeric_limits<long long>::max() / b) {
		throw std::runtime_error("Error: Overflow occurred");
	}

	return a * b;
}

constexpr long long RPN::_divide(long long a, long long b) {
	if (b == 0) {
		throw std::runtime_error("Error: Can't divide by 0");
	}

	return (a / b);
}

void RPN::calculate(char** argv) {
	std::stack<long long> stack;
	std::istringstream iss;
	std::string token;

	while (*argv != NULL) {
		iss.clear();
		iss.str(*argv);

		while (iss >> token) {
			if (token.length() > 1 || !_isRpnToken(token[0])) {
				throw std::invalid_argument("Invalid argument: " + token);
			}

			if (::isdigit(token[0])) {
				stack.push(static_cast<int>(token[0] - 48));
				continue;
			}

			if (stack.size() < 2) {
				throw std::invalid_argument("Invalid argument: Require more operand(s) to perform operator " + token);
			}

			_handleCalculation(stack, token[0]);
		}

		argv++;
	}

	if (stack.size() != 1) {
		throw std::invalid_argument("Invalid argument: Require more operator(s)");
	}

	std::cout << stack.top() << std::endl;
}

void RPN::_handleCalculation(std::stack<long long>& stack, const char rpnOperator) {
	long long rightOperand = stack.top();
	stack.pop();
	long long leftOperand = stack.top();
	stack.pop();

	long long result;

	if (rpnOperator == '+') result = _add(leftOperand, rightOperand);
	if (rpnOperator == '-') result = _subtract(leftOperand, rightOperand);
	if (rpnOperator == '*') result = _multiply(leftOperand, rightOperand);
	if (rpnOperator == '/') result = _divide(leftOperand, rightOperand);

	stack.push(result);
}
