/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:41:28 by arobu             #+#    #+#             */
/*   Updated: 2023/06/25 23:29:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Fixed{
		public:
			Fixed(void);
			Fixed(int const integer);
			Fixed(float const frac);
			~Fixed(void);
			Fixed(Fixed const &copy);
			Fixed					&operator=(Fixed const &copy);
			friend std::ostream 	&operator<<(std::ostream &out, Fixed const &fixed);
			int						getRawBits(void) const;
			void					setRawBits(int const raw);
			float					toFloat(void) const;
			int						toInt(void) const;
		private:
			int					_integer;
			static const int	_frac;
};



