/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:42:36 by arobu             #+#    #+#             */
/*   Updated: 2023/06/26 15:40:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const	int Fixed::_frac = 8;
#pragma region Orthodox Canonical Form

Fixed::Fixed(void): _integer(0){}

Fixed::Fixed(int const integer): _integer(integer << this->_frac){}

Fixed::Fixed(float const frac): _integer(frac * (1 << this->_frac)){}

Fixed::~Fixed(void){}

Fixed::Fixed(const Fixed &copy){
	*this = copy;
}

Fixed	&Fixed::operator=(const Fixed &copy){
	this->_integer = copy._integer;
	return (*this);
}

#pragma endregion

#pragma region Arithmetic Operators

Fixed	Fixed::operator+(Fixed const &copy) const{
	return (Fixed(this->toFloat() + copy.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &copy) const{
	return (Fixed(this->toFloat() - copy.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &copy) const{
	return (Fixed(this->toFloat() * copy.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &copy) const{
	return (Fixed(this->toFloat() / copy.toFloat()));
}

#pragma endregion

#pragma region Comparison Operators

bool	Fixed::operator==(Fixed const &copy) const{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(Fixed const &copy) const{
	return (this->toFloat() != copy.toFloat());
}

bool	Fixed::operator<(Fixed const &copy) const{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator<=(Fixed const &copy) const{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator>(Fixed const &copy) const{
	return (this->toFloat() > copy.toFloat());
}

bool	Fixed::operator>=(Fixed const &copy) const{
	return (this->toFloat() >= copy.toFloat());
}

#pragma endregion

#pragma region Static Member Functions

const Fixed	&Fixed::min(Fixed const &f1, Fixed const &f2){
	if (f1.toFloat() < f2.toFloat())
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(Fixed const &f1, Fixed const &f2){
	if (f1.toFloat() > f2.toFloat())
		return (f1);
	return (f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2){
	if (f1.toFloat() < f2.toFloat())
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2){
	if (f1.toFloat() > f2.toFloat())
		return (f1);
	return (f2);
}

#pragma endregion

#pragma region Class Member Functions
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
#pragma endregion

#pragma region Increment / Decrement Operators

Fixed	&Fixed::operator++(void){
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void){
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed	temp;

	temp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed	Fixed::operator--(int){
	Fixed temp;

	temp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

#pragma endregion

std::ostream &operator<<(std::ostream &out, Fixed const &fixed){
	return (out << (float)fixed.toFloat());
}
