/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:45:52 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/13 19:01:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int number) : _value(number << _fractionalBits) {}

Fixed::Fixed(const float number)
	: _value(
		static_cast<int>(std::roundf(number * (1 << _fractionalBits)))
	) {
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed() {}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

int Fixed::getRawBits() const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}

bool Fixed::operator>(const Fixed& other) {
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed& other) {
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed& other) {
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed& other) {
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed& other) {
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed& other) {
	return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed& other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	++_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = Fixed(*this);
	++_value;
	return temp;
}

Fixed& Fixed::operator--() {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = Fixed(*this);
	_value--;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a._value <= b._value ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a._value >= b._value ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a._value <= b._value ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a._value >= b._value ? a : b);
}
