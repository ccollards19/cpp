#include "Fixed.hpp"
#include "iostream"
#include "cmath"

Fixed::Fixed ()
	: value(0)
{
	std::cout<<"default constructor called"<<std::endl;
}

Fixed::Fixed (int const nbr)
{
	std::cout<<"int constructor called"<<std::endl;
	value = nbr << 8;
}

Fixed::Fixed (float const nbr)
{
	std::cout<<"float constructor called"<<std::endl;
	float integ = roundf(nbr);
	float frac = nbr - roundf(nbr);
	this->value = static_cast<int>(integ);
	this->value = this->value << 8;
	frac *= 256;
	this->value += static_cast<int>(frac);
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

int Fixed::toInt( void ) const
{
	return (this->value >> 8);
}

float Fixed::toFloat( void ) const
{
	float nbr;
	nbr = static_cast<float>(this->value);
	nbr /= 256;
	return nbr;
}

int	Fixed::getRawBits( void ) const
{
	return (this->value);
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

std::ostream & operator<< (std::ostream &out, const Fixed &obj)
{
	out << obj.Fixed::toFloat();
	return out;
}
