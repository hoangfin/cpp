/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:05:01 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/15 01:26:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

double calculate_area(Point const p1, Point const p2, Point const p3) {
	const Fixed signedArea(
		p1.getX() * (p2.getY() - p3.getY())
		+ p2.getX() * (p3.getY() - p1.getY())
		+ p3.getX() * (p1.getY() - p2.getY())
	);
	double area = 0.5f * signedArea.toFloat();
	return (area < 0.0f) ? -area : area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	double abc_area = calculate_area(a, b, c);
	double abp_area = calculate_area(a, b, point);
	double apc_area = calculate_area(a, point, c);
	double pbc_area = calculate_area(point, b, c);

	const double epsilon = 1e-9;
	if (abc_area <= epsilon || abp_area <= epsilon || apc_area <= epsilon || pbc_area <= epsilon)
		return false;
	if (
		abc_area - (abp_area + apc_area + pbc_area) < epsilon
		&& abc_area - (abp_area + apc_area + pbc_area) > -epsilon
	) {
		return true;
	}
	return false;
}
