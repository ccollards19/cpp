#include "Animal.hpp"
#include "iostream"

Animal::Animal ()
	: type("no type")
{
	std::cout<<"Animal Default Constructor"<<std::endl;
}

Animal::Animal (std::string type)
{
	this->type = type;
	std::cout<<"Animal Constructor"<<std::endl;
}

Animal::Animal (Animal const &old)
{
	this->type = old.type;
	std::cout<<"Animal copy Constructor"<<std::endl;
}

Animal &Animal::operator= (Animal const &old)
{
	if (&old != this)
	{
		this->type = old.type;
		std::cout<<"Animal copy assignement Constructor"<<std::endl;
	}
	return *this;
}
///////////////////////////////////////////////////////////

Animal::~Animal ()
{
	std::cout<<"Animal destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

std::string Animal::getType() const
{
	return this->type;
}
