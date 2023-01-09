#pragma once
#include <iostream>

class Zombie
{
	std::string name;

	public :
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );
