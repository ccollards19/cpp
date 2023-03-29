#include "iostream"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain *brain;
	public :
		Cat();
		Cat(std::string type);
		Cat(const Cat &obj);
		~Cat();

		Cat &operator= (Cat const &old);
		virtual void makeSound() const;
};
