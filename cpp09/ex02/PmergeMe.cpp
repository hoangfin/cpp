#include <iostream>
#include <string>
#include <algorithm>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv) {
	while (*argv != NULL) {
		int number = std::stoi(*argv);
		_numberVector.push_back(number);
		_numberSet.emplace(number);
		argv++;
	}

	std::cout << "Before:";

	for (int number : _numberVector) {
		std::cout << " " << number;
	}

	std::cout << std::endl;
}

void fordJohnsonMergeInsertion(std::vector<int>& arr) {
    const int n = arr.size();
    if (n <= 1) return;

    // Step 1: Sort all adjacent pairs
    for (int i = 0; i < n - 1; i += 2) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
        }
    }

    // Step 2: Collect larger elements of each pair and sort them
    std::vector<int> mainChain;
    for (int i = 1; i < n; i += 2) {
        mainChain.push_back(arr[i]);
    }
    std::sort(mainChain.begin(), mainChain.end());

    // Step 3: Insert smaller elements from pairs using binary search
    for (int i = 0; i < n; i += 2) {
        auto pos = std::lower_bound(mainChain.begin(), mainChain.end(), arr[i]);
        mainChain.insert(pos, arr[i]);
    }

    // Step 4: Handle odd-length case
    if (n % 2 != 0) {
        auto pos = std::lower_bound(mainChain.begin(), mainChain.end(), arr.back());
        mainChain.insert(pos, arr.back());
    }

    arr = mainChain;
}

void PmergeMe::sort() {
	const int n = _numberVector.size();
    if (n <= 1) return;

    // Step 1: Sort pairs of elements (using insertion sort for small groups)
    for (int i = 0; i < n - 1; i += 2) {
        if (_numberVector[i] > _numberVector[i + 1]) {
            std::swap(_numberVector[i], _numberVector[i + 1]);
        }
    }

    // Step 2: Create a sorted list of the larger elements in each pair
    std::vector<int> largerElements;
    for (int i = 1; i < n; i += 2) {
        largerElements.push_back(_numberVector[i]);
    }
    std::sort(largerElements.begin(), largerElements.end());

    // Step 3: Insert the smaller elements from pairs into the sorted list
    for (int i = 0; i < n; i += 2) {
        auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), _numberVector[i]);
        largerElements.insert(pos, _numberVector[i]);
    }

    // Step 4: Handle odd-length case (last unpaired element)
    if (n % 2 != 0) {
        auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), _numberVector.back());
        largerElements.insert(pos, _numberVector.back());
    }

    // Copy the result back to the original vector
    _numberVector = largerElements;

	std::cout << "After:";

	for (int number : _numberVector) {
		std::cout << " " << number;
	}

	std::cout << std::endl;
}

void PmergeMe::_makePairs() {

}