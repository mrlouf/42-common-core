/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:21:43 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/17 09:27:07 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
• a, b, c: The vertices of our beloved triangle.
• point: The point to check.
• Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on edge, it will return False.

- Calculate area A of ABC
- Calculate area A1, A2 and A3 of PAB, PAC and PBC
- If A1 + A2 + A3 = A return true, otherwise return false
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {

	Fixed A = Fixed(Point::calculateArea(a, b, c));

	if (A == Fixed(0))
		return false;

	Fixed A1 = Fixed(Point::calculateArea(point, a, b));
	Fixed A2 = Fixed(Point::calculateArea(point, b, c));
	Fixed A3 = Fixed(Point::calculateArea(point, a, c));

	if (A1 == Fixed(0) || A2 == Fixed(0) || A3 == Fixed(0))
		return false;

	if (A == A1 + A2 + A3)
		return true;
	return false;
}
