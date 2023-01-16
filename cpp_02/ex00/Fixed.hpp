#pragma once

class Fixed
{
	private :
		int			value;
		static const int	fract_bits = 8;
	public	:
		Fixed ();
		Fixed (Fixed const &old_obj);
		Fixed & operator = (int const &raw);
		~Fixed ();
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
}
