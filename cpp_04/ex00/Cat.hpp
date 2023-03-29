#pragma once
#include "iostream"

class Cat : public Animal
{
	public :
		Cat();
		Cat(std::string type);
		Cat(const Cat &obj);
		~Cat();

		Cat &operator= (Cat const &old);
		void makeSound() const;
};
