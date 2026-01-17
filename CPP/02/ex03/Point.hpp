/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nponchon <nponchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:23:25 by nponchon          #+#    #+#             */
/*   Updated: 2025/02/15 16:09:09 by nponchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point();
		Point(const Fixed x, const Fixed y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;

		static Fixed calculateArea(const Point &a, const Point &b, const Point &c);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream &operator<<(std::ostream &out, const Point &p);

#endif
