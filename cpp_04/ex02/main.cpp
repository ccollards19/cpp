#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main() 
{
	Cat cat_1 = Cat();
	Cat cat_2 = Cat();
//	Animal *anim = new Animal();

	cat_1 = cat_2;


	return 0;
}
