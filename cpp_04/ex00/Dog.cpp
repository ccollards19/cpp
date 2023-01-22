#include "Animal.hpp"
#include "Dog.hpp"
#include "iostream"

Dog::Dog ()
{
	std::cout<<"Dog Default Constructor"<<std::endl;
}

Dog::Dog (std::string type)
{
	this->type = type;
	std::cout<<"Dog Constructor"<<std::endl;
}

Dog::Dog (Dog const &old)
{
	this->type = old.type;
	std::cout<<"Dog copy Constructor"<<std::endl;
}

Dog &Dog::operator= (Dog const &old)
{
	this->type = old.type;
	std::cout<<"Dog copy assignement Constructor"<<std::endl;
	return *this;
}
///////////////////////////////////////////////////////////

Dog::~Dog ()
{
	std::cout<<"Dog destructor"<<std::endl;
}
///////////////////////////////////////////////////////////
void Dog::makeSound() const
{
	std::cout<<"Dog sound"<<std::endl;
}
