#pragma once
#include "iostream"

class WrongAnimal
{
	protected :
		std::string type;
	public :
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &obj);
		~WrongAnimal();

		WrongAnimal &operator= (WrongAnimal const &old);
		virtual void makeSound() const;
		std::string getType() const ;
};
