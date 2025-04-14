#pragma once

#include <type_traits>

template<typename T>
void swap(T& first, T& second) {
	T temp = first;
	first = second;
	second = temp;
}

template<typename T>
typename std::enable_if<
	std::is_convertible<decltype(std::declval<T>() < std::declval<T>()), bool>::value,
	const T&
>::type min(const T& first, const T& second) {
	if (first < second) {
		return first;
	}

	return second;
}

template<typename T>
typename std::enable_if<
	std::is_convertible<decltype(std::declval<T>() > std::declval<T>()), bool>::value,
	const T&
>::type max(const T& first, const T& second) {
	if (first > second) {
		return first;
	}

	return second;
}