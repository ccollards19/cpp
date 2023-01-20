#pragma once
#include <iostream>

class Fixed
{
	private :
		int			value;
		static const int	fract_bits = 8;
	public	:
		Fixed ();
		Fixed (Fixed const &old_obj);
		Fixed (float const nbr);
		Fixed (int const nbr);
		Fixed & operator = (Fixed const &old_obj);
		~Fixed ();
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream & operator<< (std::ostream &out, const Fixed &obj);
