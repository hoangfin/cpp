/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:05:08 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/13 22:15:26 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;
		Point& operator=(const Point& point) = delete;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif