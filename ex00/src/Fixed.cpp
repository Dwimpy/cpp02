/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:42:36 by arobu             #+#    #+#             */
/*   Updated: 2023/06/25 22:51:11 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::_frac = 8;

Fixed::Fixed(void): _integer(0){
	std::cout << "Default constructor called" << std::endl;	
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_integer);
}

void	Fixed::setRawBits(int const raw){
	this->_integer = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
