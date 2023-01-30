#pragma once
#include "iostream"
#include "Brain.hpp"

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(std::string type);
		Animal(const Animal &obj);
		~Animal();

		Animal &operator= (Animal const &old);
		virtual void makeSound() const = 0;
		std::string getType() const ;
};
