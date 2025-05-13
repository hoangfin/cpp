#include <iostream>
#include <string>
#include <charconv>
#include <algorithm>
#include <iomanip>
#include <limits>
#include "PmergeMe.hpp"

using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<double, std::milli>;

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
			if (std::find(_vector.begin(), _vector.end(), number) != _vector.end())
				throw std::runtime_error("Error: Duplicate number " + std::to_string(number));
			if (number < 0)
				throw std::invalid_argument("Error: Number must be > 0");

			_vector.push_back(number);
			_list.push_back(number);
		}

		argv++;
	}

	std::cout << "Before:";

	for (int number : _vector) {
		std::cout << " " << number;
	}

	std::cout << std::endl;
}

void PmergeMe::sort() {
	auto vectorDuration = _sortVector(_vector);
	auto listDuration = _sortList(_list);
	auto listIt = _list.begin();

	if (_vector.size() != _list.size()) {
		throw std::runtime_error("Error: Total elements in std::vector and std::set mismatched");
	}

	std::cout << "After:";

	for (auto it = _vector.begin(); it != _vector.end(); it++, listIt++) {
		if (*it != *listIt) {
			throw std::runtime_error("Error: Element value in std::vector and std::set mismatched");
		}

		std::cout << " " << *it;
	}

	std::cout
		<< "\nTime to process a range of " << _vector.size() <<  " elements with std::vector: "
		<< std::fixed << std::setprecision(4) << vectorDuration.count() << " us"
		<< "\nTime to process a range of " << _list.size() <<  " elements with std::list: "
		<< std::fixed << std::setprecision(4) << listDuration.count() << " us"
		<< std::endl;
}

Duration PmergeMe::_sortVector(std::vector<int> &vector) {
	auto start = Clock::now();
	const std::size_t length = vector.size();

    if (length <= 1) return Duration(Clock::now() - start);

    std::vector<int> smallNumbers;
    std::vector<int> mainChain;

    // Phase 1: Pairing and sorting each pair
    for (size_t i = 0; i + 1 < length; i += 2) {
        if (vector[i] < vector[i + 1]) {
			smallNumbers.push_back(vector[i]);
			mainChain.push_back(vector[i + 1]);
		} else {
			smallNumbers.push_back(vector[i + 1]);
			mainChain.push_back(vector[i]);
		}
    }

    if (length % 2 == 1) {
        mainChain.push_back(vector.back());
	}

	_sortVector(mainChain);

	// Phase 2: Insert min values using Jacobsthal sequence
	PmergeMe::_insert(mainChain, smallNumbers);
	vector = mainChain;
	return Duration(Clock::now() - start);
}

Duration PmergeMe::_sortList(std::list<int> &list) {
	auto start = Clock::now();
	const std::size_t length = list.size();

    if (length <= 1) return Duration(Clock::now() - start);

    std::list<int> smallNumbers;
    std::list<int> mainChain;

    for (auto it = list.begin(); it != list.end();) {
		auto next = std::next(it, 1);

		if (next == list.end()) {
			break;
		}

        if (*it < *next) {
			smallNumbers.push_back(*it);
			mainChain.push_back(*next);
		} else {
			smallNumbers.push_back(*next);
			mainChain.push_back(*it);
		}

		std::advance(it, 2);
    }

    if (length % 2 == 1) {
        mainChain.push_back(list.back());
	}

	_sortList(mainChain);
	PmergeMe::_insert(mainChain, smallNumbers);
	list = mainChain;
	return Duration(Clock::now() - start);
}

void PmergeMe::_insert(std::vector<int>& dest, const std::vector<int>& src) {
	std::vector<int> jacobs = _jacobsthalVector(src.size());
    std::vector<bool> insertedAt(src.size(), false);

	for (std::size_t i = 2; i < jacobs.size(); i++) {
        std::size_t insertionIdx = jacobs[i] - 1;

        if (insertionIdx < src.size() && insertedAt[insertionIdx] == false) {
			auto pos = std::lower_bound(dest.begin(), dest.end(), src[insertionIdx]);
			dest.insert(pos, src[insertionIdx]);
            insertedAt[insertionIdx] = true;
        }
    }

	for (size_t i = 0; i < src.size(); i++) {
		if (insertedAt[i] == false) {
			auto pos = std::lower_bound(dest.begin(), dest.end(), src[i]);
			dest.insert(pos, src[i]);
		}
	}
}

void PmergeMe::_insert(std::list<int>& dest, const std::list<int>& src) {
	std::list<int> jacobs = _jacobsthalList(src.size());
    std::list<bool> insertedAt(src.size(), false);
	auto insertedAtIt = insertedAt.begin();

	for (auto it = std::next(jacobs.begin(), 2); it != jacobs.end(); it++, insertedAtIt++) {
        std::size_t insertionIdx = *it - 1;

		if (insertionIdx >= src.size()) {
			continue;
		}

		auto insertedAtNext = std::next(insertedAt.begin(), insertionIdx);

		if (*insertedAtNext == false) {
			auto next = std::next(src.begin(), insertionIdx);
			auto pos = std::lower_bound(dest.begin(), dest.end(), *next);
			dest.insert(pos, *next);
			*insertedAtNext = true;
		}
    }

	insertedAtIt = insertedAt.begin();

	for (auto it = src.begin(); it != src.end(); it++, insertedAtIt++) {
		if (*insertedAtIt == false) {
			auto pos = std::lower_bound(dest.begin(), dest.end(), *it);
			dest.insert(pos, *it);
		}
	}
}

std::vector<int> PmergeMe::_jacobsthalVector(int n) {
    std::vector<int> jacob = { 0, 1 };

    while (jacob.back() < n) {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }

    return jacob;
}

std::list<int> PmergeMe::_jacobsthalList(int n) {
    std::list<int> jacob = { 0, 1 };

    while (jacob.back() < n) {
        jacob.push_back(jacob.back() + 2 * (*std::prev(jacob.end(), 2)));
    }

    return jacob;
}