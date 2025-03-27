#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Identity.hpp"

Base* generate() {
	std::srand(std::time(nullptr));
	int value = std::rand() % 3;

	switch (value) {
	  case 0: return new A;
	  case 1: return new B;
	  case 2: return new C;
	  default: return nullptr;
	}
}

void identify(Base* p) {
	A* a = dynamic_cast<A*>(p);

	if (a != nullptr) {
		std::cout << "A\n";
		return;
	}

	B* b = dynamic_cast<B*>(p);

	if (b != nullptr) {
		std::cout << "B\n";
		return;
	}

	C* c = dynamic_cast<C*>(p);

	if (c != nullptr) {
		std::cout << "C\n";
	}
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A\n";
	} catch (std::bad_cast& e) { }

	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B\n";
	} catch (std::bad_cast& e) { }

	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C\n";
	} catch (std::bad_cast& e) { }
}
