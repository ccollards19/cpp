#include "iostream"

class Dog : public  Animal
{
	private :
		Brain *brain;
	public :
		Dog();
		Dog(std::string type);
		Dog(const Dog &obj);
		~Dog();

		Dog &operator= (Dog const &old);
		void makeSound() const;
};
