#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btcExchange;

		btcExchange.display(argv[1]);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}
