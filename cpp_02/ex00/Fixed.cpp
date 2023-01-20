#include "Fixed.hpp"
#include "iostream"

Fixed::Fixed ()
	: value(0)
{
	std::cout<<"default constructor called"<<std::endl;
}

Fixed::Fixed (Fixed const &old)
{
	std::cout<<"copy constructor called"<<std::endl;
	this->value = old.getRawBits();
}

Fixed &Fixed::operator= (Fixed const &old)
{
	std::cout<<"copy constructor called"<<std::endl;
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
