#include "Fixed.hpp"
#include "iostream"

Fixed::Fixed ()
	: value(0)
{
	std::cout<<"default constructor called"<<std::endl;
}

Fixed::Fixed (Fixed const &old)
	: value(old.getRawBits())
{
	std::cout<<"copy constructor called"<<std::endl;
}

Fixed &Fixed::operator= (Fixed const &old)
{
	std::cout<<"copy constructor called"<<std::endl;
	if (&old != this)
		this->value = old.getRawBits();
	return *this;
}

Fixed::~Fixed ()
{
	std::cout<<"destructor called"<<std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits called"<<std::endl;
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout<<"setRawBits called"<<std::endl;
	this->value = raw;
}
