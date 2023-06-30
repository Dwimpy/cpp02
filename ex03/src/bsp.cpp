/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:47:41 by arobu             #+#    #+#             */
/*   Updated: 2023/06/26 16:08:59 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p){
	Fixed s;
	Fixed t;
	Fixed d;
    s = (a.getX() - c.getX()) * (p.getY() - c.getY()) - (a.getY() - c.getY()) * (p.getX() - c.getX());
    t = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
	if (((s < 0) != (t < 0)) && (s != 0) && (t != 0))
		return (false);
	d = (c.getX() - b.getX()) * (p.getY() - b.getY()) - (c.getY() - b.getY()) * (p.getX() - b.getX());
	return (d == 0 || ((d < 0) == (s + t <= 0)));
}
