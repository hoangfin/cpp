#pragma once

#include <cstddef>

// Develop a class template Array that contains elements of type T and that implements
// the following behavior and functions:
// • Construction with no parameter: Creates an empty array.
// • Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
// • Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.
// As usual, ensure everything works as expected and turn in a main.cpp file that contains your tests.

template<typename T>
class Array {
	public:
		Array() : _elements(nullptr), _size(0) {}
		Array(unsigned int n) : _elements(new T[n]), _size(n) {}

		Array(const Array& other) : _elements(new T[other._size]), _size(other._size) {
			std::copy(other._elements, other._elements + _size, _elements);
		}

		~Array() {
			delete[] _elements;
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _elements;
				_size = other._size;
				_elements = new T[_size];
				std::copy(other._elements, other._elements + _size, _elements);
			}

			return *this;
		}

		T& operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}

			return _elements[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}

			return _elements[index];
		}

		unsigned int size() const {
			return _size;
		}

	private:
		T* _elements;
		unsigned int _size;
};
