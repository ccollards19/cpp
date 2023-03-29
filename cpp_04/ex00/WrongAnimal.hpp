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
		virtual ~WrongAnimal();

		WrongAnimal &operator= (WrongAnimal const &old);
		void makeSound() const;
		std::string getType() const ;
};
