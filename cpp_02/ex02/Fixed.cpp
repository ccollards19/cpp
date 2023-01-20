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
	this->value = nbr << 8;
}

Fixed::Fixed (float const nbr)
{
	std::cout<<"float constructor called"<<std::endl;
	float integ;
	float frac = std::modf(nbr, &integ);
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
///////////////////////////////////////////////////////////

Fixed::~Fixed ()
{
	std::cout<<"destructor called"<<std::endl;
}
///////////////////////////////////////////////////////////

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

Fixed const &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 >= obj2) 
		return obj2;
	return obj1;
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1 >= obj2) 
		return obj2;
	return obj1;
}

Fixed const &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1 <= obj2) 
		return obj2;
	return obj1;
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 <= obj2) 
		return obj2;
	return obj1;
}
///////////////////////////////////////////////////////////

std::ostream & operator<< (std::ostream &out, const Fixed &obj)
{
	out << obj.Fixed::toFloat();
	return out;
}
///////////////////////////////////////////////////////////

bool Fixed::operator == (Fixed const &old_obj) const
{
	return (this->getRawBits() == old_obj.getRawBits());
}

bool  Fixed::operator != (Fixed const &old_obj) const
{
	return (this->value != old_obj.value);
}

bool  Fixed::operator <= (Fixed const &old_obj) const
{
	return (this->value <= old_obj.value);
}

bool  Fixed::operator >= (Fixed const &old_obj) const
{
	return (this->value >= old_obj.value);
}
///////////////////////////////////////////////////////////

Fixed Fixed::operator + (Fixed const &old_obj)
{
	Fixed ret(this->value + old_obj.value);
	return (ret);
}

Fixed Fixed::operator / (Fixed const &old_obj)
{
	Fixed ret(this->toFloat() / old_obj.toFloat());
	return (ret);
}

Fixed Fixed::operator * (Fixed const &old_obj)
{
	Fixed ret(this->toFloat() * old_obj.toFloat());
	return (ret);
}

Fixed Fixed::operator - (Fixed const &old_obj)
{
	Fixed ret(this->value - old_obj.value);
	return (ret);
}
///////////////////////////////////////////////////////////

Fixed & Fixed::operator ++ ()
{
	(this->value)++;
	return *this;
}

float Fixed::operator ++ (int)
{
	float ret = this->toFloat();
	(this->value)++;
	return ret;
}

Fixed & Fixed::operator -- ()
{
	(this->value)--;
	return *this;
}

float Fixed::operator -- (int)
{
	float ret = this->toFloat();
	(this->value)--;
	return ret;
}

