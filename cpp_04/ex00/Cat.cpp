#include "Animal.hpp"
#include "Cat.hpp"
#include "iostream"

Cat::Cat ()
{
	std::cout<<"Cat Default Constructor"<<std::endl;
}

Cat::Cat (std::string type)
{
	this->type = type;
	std::cout<<"Cat Constructor"<<std::endl;
}

Cat::Cat (Cat const &old)
{
	this->type = old.type;
	std::cout<<"Cat copy Constructor"<<std::endl;
}

Cat &Cat::operator= (Cat const &old)
{
	if (&old != this)
	{
		this->type = old.type;
		std::cout<<"Cat copy assignement Constructor"<<std::endl;
	}
	return *this;
}
///////////////////////////////////////////////////////////

Cat::~Cat ()
{
	std::cout<<"Cat destructor"<<std::endl;
}
///////////////////////////////////////////////////////////
void Cat::makeSound() const
{
	std::cout<<"Cat sound"<<std::endl;
}
