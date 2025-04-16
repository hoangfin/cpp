#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec = { 10, 20, 30, 40 };
	std::list<int> lst = {5, 15, 25, 35};
	std::deque<int> dq = {100, 200, 300};
    std::set<int> s = {1, 3, 5, 7};
    std::vector<int> emptyVec;

    try {
        auto it = easyfind(vec, 30);
        std::cout << "[vector] Found: " << *it << std::endl;
		easyfind(vec, 100);
    } catch (const std::exception& e) {
        std::cout << "[vector] Error: " << e.what() << std::endl;
    }

    try {
        auto it = easyfind(lst, 15);
        std::cout << "[list] Found: " << *it << std::endl;
		easyfind(lst, 99);
    } catch (const std::exception& e) {
        std::cout << "[list] Error: " << e.what() << std::endl;
    }

    try {
        auto it = easyfind(dq, 200);
        std::cout << "[deque] Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "[deque] Error: " << e.what() << std::endl;
    }

    try {
        auto it = easyfind(s, 5);
        std::cout << "[set] Found: " << *it << std::endl;
		easyfind(s, 42);
    } catch (const std::exception& e) {
        std::cout << "[set] Error: " << e.what() << std::endl;
    }

    try {
        easyfind(emptyVec, 42);
    } catch (const std::exception& e) {
        std::cout << "[empty vector] Not found: " << e.what() << std::endl;
    }

	return 0;
}