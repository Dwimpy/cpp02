/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:41:28 by arobu             #+#    #+#             */
/*   Updated: 2023/06/26 15:19:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Fixed{
		public:
#pragma region Orthodox Cannonical Form
			Fixed(void);
			Fixed(int const integer);
			Fixed(float const frac);
			~Fixed(void);
			Fixed(Fixed const &copy);
			Fixed					&operator=(Fixed const &copy);

#pragma endregion

#pragma region Arithmetic Operators
			Fixed					operator+(Fixed const &copy) const;
			Fixed					operator-(Fixed const &copy) const;
			Fixed					operator*(Fixed const &copy) const;
			Fixed					operator/(Fixed const &copy) const;
#pragma endregion

#pragma region Comparison Operators

			bool					operator==(Fixed const &copy) const;
			bool					operator!=(Fixed const &copy) const;
			bool					operator<(Fixed const &copy) const;
			bool					operator>(Fixed const &copy) const;
			bool					operator<=(Fixed const &copy) const;
			bool					operator>=(Fixed const &copy) const;	
#pragma endregion

#pragma region Increment / Decrement Operators

			Fixed					&operator++(void);
			Fixed					&operator--(void);
			Fixed					operator++(int);
			Fixed					operator--(int);

#pragma endregion
			friend std::ostream 	&operator<<(std::ostream &out, Fixed const &fixed);

#pragma region Static Member Functions
			static const Fixed		&min(Fixed const &f1, Fixed const &f2);
			static const Fixed		&max(Fixed const &f1, Fixed const &f2);
			static Fixed			&min(Fixed &f1, Fixed &f2);
			static Fixed			&max(Fixed &f1, Fixed &f2);
#pragma endregion

#pragma region Class Member Functions
			int						getRawBits(void) const;
			int						toInt(void) const;
			float					toFloat(void) const;
			void					setRawBits(int const raw);
#pragma endregion

		private:
			int					_integer;
			static const int	_frac;
};



