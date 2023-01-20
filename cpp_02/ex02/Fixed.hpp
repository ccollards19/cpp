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
		~Fixed ();

		Fixed & operator = (Fixed const &old_obj);
		
		bool operator == (Fixed const &old_obj) const;
		bool operator != (Fixed const &old_obj) const;
		bool operator <= (Fixed const &old_obj) const;
		bool operator >= (Fixed const &old_obj) const;

		Fixed operator + (Fixed const &old_obj);
		Fixed operator / (Fixed const &old_obj);
		Fixed operator * (Fixed const &old_obj);
		Fixed operator - (Fixed const &old_obj);


		Fixed & operator ++ ();
		float operator ++ (int);
		Fixed & operator -- ();
		float operator -- (int);

		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float toFloat( void ) const;
		int toInt( void ) const;

		static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
		static Fixed &min(Fixed &obj1, Fixed &obj2);
		static const Fixed &max(const Fixed &obj1, const Fixed &obj2);
		static Fixed &max(Fixed &obj1, Fixed &obj2);
};

std::ostream & operator<< (std::ostream &out, const Fixed &obj);
