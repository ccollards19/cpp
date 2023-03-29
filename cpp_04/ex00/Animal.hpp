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

		Animal &operator= (Animal const &old);
		virtual void makeSound() const;
		std::string getType() const ;
};
