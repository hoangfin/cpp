#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Error: Argument(s) required." << std::endl;
		return 1;
	}

	try {
		PmergeMe pm(argv + 1);
		pm.sortVector();
		pm.printResult();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
