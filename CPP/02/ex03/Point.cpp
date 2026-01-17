/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:21:52 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/15 16:09:33 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}

Point::Point(const Point &other) {
	*this = other;
}

Point &Point::operator=(const Point &other) {
	if (this != &other) {
		const_cast<Fixed&>(_x) = other._x;
		const_cast<Fixed&>(_y) = other._y;
	}
	return *this;
}

Point::~Point() {}

Fixed Point::calculateArea(const Point &a, const Point &b, const Point &c) {

	Fixed area((a._x * (b._y - c._y) + b._x * (c._y - a._y) + c._x * (a._y - b._y)) / 2);

	(area < 0) ? area = area * -1 : area ;
	return area;
}

Fixed Point::getX() const {
	return this->_x;
}

Fixed Point::getY() const {
	return this->_y;
}

std::ostream &operator<<(std::ostream &out, const Point &p) {
	out << "<" << p.getX() << "," << p.getY() << ">";
	return out;
}
