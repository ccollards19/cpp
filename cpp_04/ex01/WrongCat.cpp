#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "iostream"

WrongCat::WrongCat ()
{
	std::cout<<"WrongCat Default Constructor"<<std::endl;
}

WrongCat::WrongCat (std::string type)
{
	this->type = type;
	std::cout<<"WrongCat Constructor"<<std::endl;
}

WrongCat::WrongCat (WrongCat const &old)
{
	this->type = old.type;
	std::cout<<"WrongCat copy Constructor"<<std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &old)
{
	if (&old != this)
	{
		this->type = old.type;
		std::cout<<"WrongCat copy assignement Constructor"<<std::endl;
	}
	return *this;
}
///////////////////////////////////////////////////////////

WrongCat::~WrongCat ()
{
	std::cout<<"WrongCat destructor"<<std::endl;
}
///////////////////////////////////////////////////////////
void WrongCat::makeSound() const
{
	std::cout<<"WrongCat sound"<<std::endl;
}
