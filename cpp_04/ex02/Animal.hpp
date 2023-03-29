#pragma once
#include "iostream"

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		Animal(std::string type);
		Animal(const Animal &obj);
		virtual ~Animal();

		virtual Animal &operator= (Animal const &old);
		virtual void makeSound() const = 0;
		std::string getType() const ;
};
