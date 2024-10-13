/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:12:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/13 22:16:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& point) :_x(point._x), _y(point._y) {}

Point::~Point() {}

const Fixed& Point::getX() const {
	return _x;
}

const Fixed& Point::getY() const {
	return _y;
}
