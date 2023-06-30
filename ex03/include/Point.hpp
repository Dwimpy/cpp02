/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:21:30 by arobu             #+#    #+#             */
/*   Updated: 2023/06/30 13:48:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point{
		public:
			Point(Fixed const x, Fixed const y);
			Point(float const x, float const y);
			Point(int const x, int const y);
			Point(float const x, int const y);
			Point(int const x, float const y);
			Point(void);
			~Point(void);
			Point(Point const &copy);
			Point	&operator=(Point &copy);
			
			// Getters
			Fixed	getX() const;
			Fixed	getY() const;
		private:
			Fixed const	_x;
			Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const p);
