#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main() 
{
	Animal *cat_1 = new Cat();
	Animal *cat_2 = new Cat();
//	Animal *anim = new Animal();

	*cat_1 = *cat_2;

	delete cat_1;
	delete cat_2;

	return 0;
}
