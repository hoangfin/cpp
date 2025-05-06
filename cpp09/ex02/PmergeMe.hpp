#pragma once

#include <vector>
#include <set>
#include <chrono>

class PmergeMe {
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe&) = default;
		~PmergeMe() = default;

		PmergeMe& operator=(const PmergeMe&) = default;

		void sortVector();
		void sortSet();
		void printResult();

	private:
		std::vector<int> _numberVector;
		std::set<int> _numberSet;
		std::chrono::duration<double, std::milli> _executionTimeForVector;
		// std::chrono::microseconds _executionTimeForSet;
};
