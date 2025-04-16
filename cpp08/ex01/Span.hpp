#pragma once

#include <cstddef>
#include <vector>
#include <cstdint>

class Span {
	public:
		Span() = delete;
		Span(unsigned int n);
		Span(const Span&) = default;
		~Span() = default;

		Span& operator=(const Span&) = default;

		void addNumber(int number);

		template<typename Iterator>
		void addNumber(Iterator begin, Iterator end) {
			std::size_t count = std::distance(begin, end);

			if (_numbers.size() > SIZE_MAX - count || _numbers.size() + count > _n) {
				throw std::runtime_error("Couldn't add numbers in the specified range: Exceeded capacity");
			}

			_numbers.insert(_numbers.end(), begin, end);
		};

		std::size_t shortestSpan() const;
		std::size_t longestSpan() const;

	private:
		std::size_t _n;
		std::vector<int> _numbers;
};