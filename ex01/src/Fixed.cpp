/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:42:36 by arobu             #+#    #+#             */
/*   Updated: 2023/06/26 14:07:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_frac = 8;

Fixed::Fixed(void): _integer(0){
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::Fixed(int const integer): _integer(integer << this->_frac){
	std::cout << "Default constructor called with constant integer parameter" << std::endl;
}

Fixed::Fixed(float const frac): _integer(frac * (1 << this->_frac)){
	std::cout << "Default constructor called with constant floating point number parameter" << std::endl;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy){
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &copy){
	this->_integer = copy._integer;
	std::cout << "Assignment operator called" << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const{
	return (this->_integer);
}

void	Fixed::setRawBits(int const raw){
	this->_integer = raw;
}

float	Fixed::toFloat(void) const{
	return ((float)this->_integer / (1 << this->_frac));
}

int	Fixed::toInt(void) const{
	return (this->_integer >> this->_frac);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed){
	return (out << (float)fixed.toFloat());
}
