/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:04:03 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 09:57:54 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixed + other._fixed);
	return result;
}
Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->_fixed - other._fixed);
	return result;
}
Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->_fixed * other._fixed) >> _bits);
	return result;
}
Fixed Fixed::operator/(const Fixed &other) const {
	// Directly returns 0 if division by zero
	if (other._fixed == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	Fixed result;
	result.setRawBits((this->_fixed << _bits) / other._fixed);
	return result;
}


Fixed &Fixed::operator++() {
	_fixed += 1;
	return *this;
}
Fixed &Fixed::operator--() {
	_fixed -= 1;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	setRawBits(this->_fixed + 1);
	return tmp;
}
Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	setRawBits(this->_fixed - 1);
	return tmp;
}


bool Fixed::operator>(const Fixed &other) const {
	return (_fixed > other._fixed) ? true : false;
}
bool Fixed::operator<(const Fixed &other) const {
	return (_fixed < other._fixed) ? true : false;
}
bool Fixed::operator>=(const Fixed &other) const {
	return (_fixed >= other._fixed) ? true : false;
}
bool Fixed::operator<=(const Fixed &other) const {
	return (_fixed <= other._fixed) ? true : false;
}
bool Fixed::operator==(const Fixed &other) const {
	return (_fixed == other._fixed) ? true : false;
}
bool Fixed::operator!=(const Fixed &other) const {
	return (_fixed != other._fixed) ? true : false;
}


Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}


Fixed::Fixed() : _fixed(0) {}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {

	if (this != &other) {
		this->_fixed = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {}


Fixed::Fixed(const int i) {
	_fixed = i << _bits;
}

Fixed::Fixed(const float f) {
	_fixed = roundf(f * (1 << _bits));
}

int Fixed::getRawBits() const {
	return this->_fixed;
}

void Fixed::setRawBits( int const raw ) {
	this->_fixed = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(_fixed) / (1 << _bits);
}

int Fixed::toInt( void ) const {
	return _fixed >> _bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat();
	return out;
}
