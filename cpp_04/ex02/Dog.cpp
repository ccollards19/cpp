#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "iostream"

Dog::Dog ()
{
	this->brain = new Brain;
	std::cout<<"Dog Default Constructor"<<std::endl;
}

Dog::Dog (std::string type)
{
	this->brain = new Brain;
	this->type = type;
	std::cout<<"Dog Constructor"<<std::endl;
}

Dog::Dog (Dog const &old)
{
	this->brain = new Brain(*(old.brain));
	this->type = old.type;
	std::cout<<"Dog copy Constructor"<<std::endl;
}

Dog &Dog::operator= (Dog const &old)
{
	if (&old != this)
	{
		*(this->brain) = *(old.brain);
		this->type = old.type;
		std::cout<<"Dog copy assignement Constructor"<<std::endl;
	}
	return *this;
}
///////////////////////////////////////////////////////////

Dog::~Dog ()
{
	delete this->brain;
	std::cout<<"Dog destructor"<<std::endl;
}
///////////////////////////////////////////////////////////
void Dog::makeSound() const
{
	std::cout<<"Dog sound"<<std::endl;
}
