/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:41:28 by arobu             #+#    #+#             */
/*   Updated: 2023/06/25 22:48:38 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Fixed{
		public:
			Fixed(void);
			~Fixed(void);
			Fixed(Fixed const &copy);
			Fixed	&operator=(Fixed const &copy);
			int		getRawBits(void) const;
			void	setRawBits(int const raw);
		private:
			int					_integer;
			static const int	_frac;
};



