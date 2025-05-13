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

	private:
		std::vector<int> _vector;
		std::list<int> _list;

		std::chrono::duration<double, std::milli> _sortVector(std::vector<int> &vector);
		std::chrono::duration<double, std::milli> _sortList(std::list<int> &list);
		static std::vector<int> _jacobsthalVector(int n);
		static std::list<int> _jacobsthalList(int n);
		static void _insert(std::vector<int>& dest, const std::vector<int>& src);
		static void _insert(std::list<int>& dest, const std::list<int>& src);
};
