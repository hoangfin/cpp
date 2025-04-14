#pragma once

#include <functional>

template<typename T, typename F>
void iter(T* array, std::size_t length, F fn) {
	for (std::size_t i = 0; i < length; i++) {
		fn(array[i]);
	}
}