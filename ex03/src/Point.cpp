/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:24:55 by arobu             #+#    #+#             */
/*   Updated: 2023/06/26 15:45:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0){}

Point::Point(Fixed x, Fixed y): _x(x), _y(y){}

Point::Point(float const x, float const y): _x(x), _y(y){}

Point::Point(int const x, int const y): _x(x), _y(y){}

Point::Point(int const x, float const y): _x(x), _y(y){}

Point::Point(float const x, int const y): _x(x), _y(y){}

Point::~Point(void){}

Point::Point(Point const &copy): _x(copy._x), _y(copy._y){}

Point	&Point::operator=(Point const &copy){
	return (*this);
}

Fixed	Point::getX(void) const{
	return (this->_x);
}

Fixed	Point::getY(void) const{
	return (this->_y);
}
