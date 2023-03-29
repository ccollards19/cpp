#include "iostream"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &obj);
		~WrongCat();
		WrongCat &operator=(WrongCat const &old);

		void makeSound() const;
};
