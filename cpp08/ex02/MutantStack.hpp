#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typename T::iterator begin() { return this->c.begin(); }

};