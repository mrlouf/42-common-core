/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:03:57 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/15 16:05:14 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class	Fixed {
	private:
	
		int					_fixed;
		static const int	_bits = 8;

	public:

		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		// Comparison operators
		bool operator>(const Fixed &other) const ; // last const makes calling instance const
		bool operator<(const Fixed &other) const ;
		bool operator>=(const Fixed &other) const ;
		bool operator<=(const Fixed &other) const ;
		bool operator==(const Fixed &other) const ;
		bool operator!=(const Fixed &other) const ;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Pre-increment and pre-decrement
		Fixed &operator++();
		Fixed &operator--();

		// Post-increment and post-decrement
		Fixed operator++(int);
		Fixed operator--(int);

		// 'Static' in C++ means a function is not called from an instance
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);

		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		Fixed(const int i);
		Fixed(const float f);

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;


};

// Declared outside of Class declaration since it is a free function
std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
