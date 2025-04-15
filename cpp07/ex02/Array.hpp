#pragma once

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
