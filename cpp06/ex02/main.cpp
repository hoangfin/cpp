#include <iostream>
#include "Identity.hpp"

int main() {
	Base* base;

	try {
		base = generate();
	} catch (std::exception& e) {
		e.what();
		return 1;
	}

	identify(base);
	identify(*base);
	delete base;
	return 0;
}
