/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:33:28 by hoatran           #+#    #+#             */
/*   Updated: 2024/10/15 01:27:07 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
	{
		std::cout << "/* Test-00: Degenerate Triangle */\n";
		Point a(3.3f, 2.1f);
		Point b(3.5f, 2.1f);
		Point c(3.6f, 2.1f);
		Point p(3.4f, 2.1f);
		bsp(a, b, c, p)
			? std::cout << "Point is inside\n"
			: std::cout << "Point is outside\n";
  	}
	std::cout << '\n';
	{
		std::cout << "/* Test-01: Acute Triangle */\n";
		Point a(1.0f, 1.0f);
		Point b(4.0f, 1.0f);
		Point c(2.5f, 3.0f);
		Point p(2.5f, 2.0f);
		bsp(a, b, c, p)
			? std::cout << "Point is inside\n"
			: std::cout << "Point is outside\n";
	}
	std::cout << '\n';
	{
		std::cout << "/* Test-02: Obtuse Triangle */\n";
		Point a(1.0f, 1.0f);
		Point b(6.0f, 1.0f);
		Point c(2.0f, 4.0f);
		Point p(3.0f, 2.0f);
		bsp(a, b, c, p)
			? std::cout << "Point is inside\n"
			: std::cout << "Point is outside\n";
	}
	std::cout << '\n';
	{
		std::cout << "/* Test-03: Right Triangle */\n";
		Point a(0.0f, 0.0f);
		Point b(5.0f, 0.0f);
		Point c(0.0f, 5.0f);
		Point p(2.0f, 2.0f);
		bsp(a, b, c, p)
			? std::cout << "Point is inside\n"
			: std::cout << "Point is outside\n";
	}
	std::cout << '\n';
	{
		std::cout << "/* Test-04: Point Outside the Triangle */\n";
		Point a(1.0f, 1.0f);
		Point b(5.0f, 1.0f);
		Point c(3.0f, 4.0f);
		Point p(6.0f, 3.0f);
		bsp(a, b, c, p)
			? std::cout << "Point is inside\n"
			: std::cout << "Point is outside\n";
	}
	std::cout << '\n';
	{
		std::cout << "/* Test-05: Point on the Edge of the Triangle */\n";
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.0f);
		Point c(5.0f, 0.0f);
		Point p(0.0f, 2.5f);
		bsp(a, b, c, p)
			? std::cout << "Point is inside\n"
			: std::cout << "Point is outside\n";
	}
	std::cout << '\n';
	{
		std::cout << "/* Test-06: Point at a Vertex of the Triangle */\n";
		Point a(1.0f, 1.0f);
		Point b(5.0f, 1.0f);
		Point c(3.0f, 4.0f);
		Point p(3.0f, 4.0f);
		bsp(a, b, c, p)
			? std::cout << "Point is inside\n"
			: std::cout << "Point is outside\n";
	}
	std::cout << std::endl;
  	return 0;
}
