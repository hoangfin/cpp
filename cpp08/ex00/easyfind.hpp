#pragma once

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::const_iterator easyfind(const T& container, int number) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), number);

	if (it == container.end()) {
		throw std::runtime_error("Couldn't find " + std::to_string(number));
	}

	return it;
}

template<typename T>
typename T::iterator easyfind(T& container, int number) {
	typename T::iterator it = std::find(container.begin(), container.end(), number);

	if (it == container.end()) {
		throw std::runtime_error("Couldn't find " + std::to_string(number));
	}

	return it;
}