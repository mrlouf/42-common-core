/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:04:08 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 10:05:50 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		
		std::cout << Fixed::max( a, b ) << std::endl;

		std::cout << Fixed::min( a, b ) << std::endl;
	}
	{
		std::cout << std::endl;
		Fixed a(Fixed(42.42f));
		Fixed b(Fixed(2));
		std::cout << ++a << std::endl;
		std::cout << ++b << std::endl;
		std::cout << a / b << std::endl;
		std::cout << a * b << std::endl;
		std::cout << a + b << std::endl;
		std::cout << a - b << std::endl;
		std::cout << b - a << std::endl;
		std::cout << b++ << std::endl;
		std::cout << b << std::endl;
	}

	return 0;
}
