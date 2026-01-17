/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:04:03 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 09:54:00 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

// Default constructor that initialises the fixed-point value to 0
Fixed::Fixed() : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other) {

	std::cout << "Copy assignment operator called" << std::endl;

	// Protection against self-assignment
	// std::swap(_fixed, other._fixed) would work too if not for const int
	if (this != &other) {
		this->_fixed = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	_fixed = i << _bits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(f * (1 << _bits));
}

int Fixed::getRawBits() const {

	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;

}

void Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;

}

// C++ cast the value of fixed to float and divide by 2^_bits
float Fixed::toFloat( void ) const {
	return static_cast<float>(_fixed) / (1 << _bits);
}

int Fixed::toInt( void ) const {
	return _fixed >> _bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
	out << f.toFloat(); // Print as float
	return out;
}
