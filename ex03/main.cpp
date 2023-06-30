/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:32:27 by arobu             #+#    #+#             */
/*   Updated: 2023/06/26 16:13:07 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

    Point a(0.0f, 0.0f);
    Point b(10.0f, 30.0f);
    Point c(20.0f, 0.0f);
    Point p(10.0f, 15.0f);

    // Call the bsp function and store the result
    bool result = bsp(a, b, c, p);

    // Output the result
	std::cout << "Test Case 1: ";
    if (result) {
        std::cout << "The point p is inside the triangle." << std::endl;
    } else {
        std::cout << "The point p is outside the triangle." << std::endl;
    }

    Point a2(0.0f, 0.0f);
    Point b2(10.0f, 30.0f);
    Point c2(20.0f, 0.0f);
    Point p2(30.0f, 15.0f);
    bool result2 = bsp(a2, b2, c2, p2);
    std::cout << "Test Case 2: ";
    if (result2) {
        std::cout << "Point is inside the triangle." << std::endl;
    } else {
        std::cout << "Point is outside the triangle." << std::endl;
    }

	return (0);
}
