#include <iostream>
#include <string>
#include <charconv>
#include <algorithm>
#include <iomanip>
#include <limits>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {
	int number;
	std::istringstream iss;
	std::string token;

	while (*argv != NULL) {
		iss.clear();
		iss.str(*argv);

		while (iss >> token) {
			auto result = std::from_chars(token.data(), token.data() + token.length(), number);

			if (result.ec == std::errc::invalid_argument)
				throw std::invalid_argument("Error: Not a valid integer.");
			if (result.ec == std::errc::result_out_of_range)
				throw std::runtime_error("Error: Number is too large/small for `int`.");
			if (result.ptr != token.data() + token.length())
				throw std::invalid_argument("Error: Not a valid integer.");
			if (std::find(_numberVector.begin(), _numberVector.end(), number) != _numberVector.end())
				throw std::runtime_error("Error: Duplicate number " + std::to_string(number));
			if (number < 0)
				throw std::invalid_argument("Error: Number must be > 0");

			_numberVector.push_back(number);
			_numberList.push_back(number);
		}

		argv++;
	}

	std::cout << "Before:";

	for (int number : _numberVector) {
		std::cout << " " << number;
	}

	std::cout << std::endl;
}

void PmergeMe::sort() {
	std::cout << PmergeMe::_getJacobsthalNumberByIndex(6) << std::endl;
	// _sortVector();
	// _sortList();

	// const std::size_t total = _numberVector.size();

	// if (total != _numberList.size()) {
	// 	throw std::runtime_error("Error: Total elements in std::vector and std::set mismatched");
	// }

	// std::cout << "After:";

	// auto lIt = _numberList.begin();

	// for (auto vIt = _numberVector.begin(); vIt != _numberVector.end(); vIt++, lIt++) {
	// 	if (*vIt != *lIt) {
	// 		throw std::runtime_error("Error: Element value in std::vector and std::set mismatched");
	// 	}

	// 	std::cout << " " << *vIt;
	// }

	// std::cout
	// 	<< "\nTime to process a range of " << total <<  " elements with std::vector : "
	// 	<< std::fixed << std::setprecision(4) << _executionTimeForVector.count() << " us"
	// 	<< "\nTime to process a range of " << total <<  " elements with std::set : "
	// 	<< _executionTimeForList.count() << " us"
	// 	<< std::endl;
}

void PmergeMe::_sortVector() {
	const int size = _numberVector.size();

    if (size <= 1) {
		return;
	}

	auto start = std::chrono::high_resolution_clock::now();

    // Sort all adjacent pairs
    for (int i = 0; i < size - 1; i += 2) {
        if (_numberVector[i] > _numberVector[i + 1]) {
            std::swap(_numberVector[i], _numberVector[i + 1]);
        }
    }

	if (size == 2) {
		auto end = std::chrono::high_resolution_clock::now();
		_executionTimeForVector = std::chrono::duration<double, std::milli>(end - start);
		return;
	}

    // Collect larger elements of each pair and sort them
    std::vector<int> sortedVector;

    for (int i = 1; i < size - 1; i += 2) {
        sortedVector.push_back(_numberVector[i]);
    }

    std::sort(sortedVector.begin(), sortedVector.end());

    // Insert smaller elements from pairs using binary search
    for (int i = 0; i < size - 1; i += 2) {
        auto pos = std::lower_bound(sortedVector.begin(), sortedVector.end(), _numberVector[i]);
        sortedVector.insert(pos, _numberVector[i]);
    }

    // Handle odd-length case
    if (size % 2 != 0) {
        auto pos = std::lower_bound(sortedVector.begin(), sortedVector.end(), _numberVector.back());
        sortedVector.insert(pos, _numberVector.back());
    }

    _numberVector = sortedVector;

	auto end = std::chrono::high_resolution_clock::now();
	_executionTimeForVector = std::chrono::duration<double, std::milli>(end - start);
}

void PmergeMe::_sortList() {
	const std::size_t total = _numberList.size();

	if (total <= 1) {
		return;
	}

	auto start = std::chrono::high_resolution_clock::now();
	auto it = _numberList.begin();
	auto end = _numberList.end();

	while (it != end && std::distance(it, end) >= 2) {
		auto nextIt = std::next(it, 1);

		if (*it > *nextIt) {
			std::swap(*it, *nextIt);
		}

		std::advance(it, 2);
	}

	if (total == 2) {
		auto end = std::chrono::high_resolution_clock::now();
		_executionTimeForList = std::chrono::duration<double, std::milli>(end - start);
		return;
	}

	std::list<int> sortedList;
	it = std::next(_numberList.begin(), 1);

	while (it != end && std::distance(it, end) >= 2) {
		sortedList.push_back(*it);
		std::advance(it, 2);
	}

	sortedList.sort();

	it = _numberList.begin();

	while (it != end && std::distance(it, end) >= 2) {
		auto pos = std::lower_bound(sortedList.begin(), sortedList.end(), *it);
		sortedList.insert(pos, *it);
		std::advance(it, 2);
	}

	if (total % 2 != 0) {
		auto pos = std::lower_bound(sortedList.begin(), sortedList.end(), _numberList.back());
		sortedList.insert(pos, _numberList.back());
	}

	_numberList = sortedList;

	auto endTime = std::chrono::high_resolution_clock::now();
	_executionTimeForList = std::chrono::duration<double, std::milli>(endTime - start);
}

/**
 * The Jacobsthal number at a specific point in the sequence may be calculated directly
 * using the closed-form equation: J(n) = (2^n - (-1)^n) / 3
 * */
std::size_t PmergeMe::_getJacobsthalNumberByIndex(std::size_t index) {
	if (index == 0) return 0;
	if (index == 1) return 1;

	if (index >= std::numeric_limits<std::size_t>::digits) {
		throw std::overflow_error("Error: Overflow occurred by index = " + std::to_string(index));
	}

	const std::size_t term1 = std::size_t{1} << index;	// 2^n
	const int term2 = (index % 2 == 0 ? 1 : -1);		// (-1)^n
	return static_cast<std::size_t>((term1 - term2) / 3);
}
