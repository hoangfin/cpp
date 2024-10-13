/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:33:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/13 23:49:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
	Point a(1.1f, 1.1f);
	Point b(3.3f, 3.3f);
	Point c(5.5f, 1.8f);
	Point point(1.1f, 1.1f);

	std::cout << "Is point within triangle boundary? " << bsp(a, b, c, point) << std::endl;
	return 0;
}
