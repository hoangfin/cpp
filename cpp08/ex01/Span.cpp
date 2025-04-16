#include <stdexcept>
#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {
	_numbers.reserve(n);
}

void Span::addNumber(int number) {
	if (_numbers.size() == _n) {
		throw std::runtime_error("Couldn't add " + std::to_string(number) + ": Reached max capacity");
	}

	_numbers.push_back(number);
}

std::size_t Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw std::runtime_error("Couldn't calculate shortest span: span has less than 2 numbers stored");
	}

	std::size_t shortestDistance = SIZE_MAX;

	for (std::size_t i = 0; i < _numbers.size() - 1; i++) {
		std::size_t distance = std::abs(_numbers[i] - _numbers[i + 1]);

		if (distance < shortestDistance) {
			shortestDistance = distance;
		}
	}

	return shortestDistance;
}

std::size_t Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw std::runtime_error("Couldn't calculate longest span: span has less than 2 numbers stored");
	}

	std::size_t longestDistance = 0;

	for (std::size_t i = 0; i < _numbers.size() - 1; i++) {
		std::size_t distance = std::abs(_numbers[i] - _numbers[i + 1]);

		if (distance > longestDistance) {
			longestDistance = distance;
		}
	}

	return longestDistance;
}
