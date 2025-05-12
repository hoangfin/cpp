#pragma once

#include <vector>
#include <list>
#include <chrono>

class PmergeMe {
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe&) = default;
		~PmergeMe() = default;

		PmergeMe& operator=(const PmergeMe&) = default;

		void sort();
		void _sortVector();
		void _sortList();
		void printResult();

	private:
		std::vector<int> _numberVector;
		std::list<int> _numberList;
		std::chrono::duration<double, std::milli> _executionTimeForVector;
		std::chrono::duration<double, std::milli> _executionTimeForList;

		static int _getJacobsthalNumber(int n);
};
