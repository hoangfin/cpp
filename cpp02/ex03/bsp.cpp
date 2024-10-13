/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:05:01 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/13 23:45:52 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	const Fixed& minX = Fixed::min(
		Fixed::min(a.getX(), b.getX()), c.getX()
	);
	const Fixed& maxX = Fixed::max(
		Fixed::max(a.getX(), b.getX()), c.getX()
	);
	const Fixed& minY = Fixed::min(
		Fixed::min(a.getY(), b.getY()), c.getY()
	);
	const Fixed& maxY = Fixed::max(
		Fixed::max(a.getY(), b.getY()), c.getY()
	);
	if (
		const_cast<Fixed&>(point.getX()) > minX
		&& const_cast<Fixed&>(point.getX()) < maxX
		&& const_cast<Fixed&>(point.getY()) > minY
		&& const_cast<Fixed&>(point.getY()) < maxY
	) {
		return true;
	}
	return false;
}
