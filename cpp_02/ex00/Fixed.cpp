#include "Fixed.hpp"

Fixed ()
	: value(0)
{
	std::cout<<"default constructor called"<<std::endl;

}

Fixed (int const &raw)
	: value(raw)
{
	std::cout<<"copy constructor called"<<std::endl;

}

Fixed & operator = (int const &raw)
	: value(raw)
{
	std::cout<<""<<std::endl;

}

~Fixed ();
{
	std::cout<<""<<std::endl;
}

int	getRawBits( void ) const
{
	std::cout<<""<<std::endl;
	
}

void	setRawBits( int const raw )
{
	std::cout<<""<<std::endl;

}
