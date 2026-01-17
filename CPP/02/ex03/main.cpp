/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:04:08 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 09:26:56 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
		Fixed x1(Fixed(1));
		Fixed y1(Fixed(2));
		Point A(x1, y1);

		Fixed x2(Fixed(7));
		Fixed y2(Fixed(19));
		Point B(x2, y2);

		Fixed x3(Fixed(15));
		Fixed y3(Fixed(0));
		Point C(x3, y3);

		std::cout << "A" << A << std::endl;
		std::cout << "B" << B << std::endl;
		std::cout << "C" << C << std::endl;
		std::cout << std::endl;

		Fixed x4(Fixed(3));
		Fixed y4(Fixed(7.76f));
		Point P(x4, y4);

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (i == A.getX().toInt() && j == A.getY().toInt())
					std::cout << "A";
				else if (i == B.getX().toInt() && j == B.getY().toInt())
					std::cout << "B";
				else if (i == C.getX().toInt() && j == C.getY().toInt())
					std::cout << "C";
				else if (i == P.getX().toInt() && j == P.getY().toInt())
					std::cout << "P";
				else
					std::cout << " ";
			}
			std::cout << std::endl;
		}

		if (bsp(A, B, C, P))
			std::cout << "True" << std::endl;
		else
			std::cout << "False" << std::endl;

	return 0;
}
