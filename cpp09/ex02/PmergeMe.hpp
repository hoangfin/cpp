#pragma once

#include <vector>
#include <set>

class PmergeMe {
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe&) = default;
		~PmergeMe() = default;

		PmergeMe& operator=(const PmergeMe&) = default;

		void sort();

	private:
		std::vector<int> _numberVector;
		std::vector<std::pair<int, int>> _pairs;
		std::set<int> _numberSet;

		void _makePairs();
};
