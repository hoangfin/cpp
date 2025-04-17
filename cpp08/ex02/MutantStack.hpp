#pragma once

#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		using iterator = typename std::stack<T>::container_type::iterator;
		using const_iterator = typename std::stack<T>::container_type::const_iterator;
    	using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
    	using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack& other) : std::stack<T>(other) {};
		~MutantStack() = default;

		MutantStack& operator=(const MutantStack& other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}

			return *this;
		};

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.end(); }
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.end(); }
};
