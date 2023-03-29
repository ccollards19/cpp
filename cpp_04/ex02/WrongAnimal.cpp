#include "WrongAnimal.hpp"
#include "iostream"

WrongAnimal::WrongAnimal ()
	: type("no type")
{
	std::cout<<"WrongAnimal Default Constructor"<<std::endl;
}

WrongAnimal::WrongAnimal (std::string type)
{
	this->type = type;
	std::cout<<"WrongAnimal Constructor"<<std::endl;
}

WrongAnimal::WrongAnimal (WrongAnimal const &old)
{
	this->type = old.type;
	std::cout<<"WrongAnimal copy Constructor"<<std::endl;
}

WrongAnimal &WrongAnimal::operator= (WrongAnimal const &old)
{
	if (&old != this)
	{
		this->type = old.type;
		std::cout<<"WrongAnimal copy assignement Constructor"<<std::endl;
	}
	return *this;
}
///////////////////////////////////////////////////////////

WrongAnimal::~WrongAnimal ()
{
	std::cout<<"WrongAnimal destructor"<<std::endl;
}
///////////////////////////////////////////////////////////
void WrongAnimal::makeSound() const
{
	std::cout<<"WrongAnimal sound"<<std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
