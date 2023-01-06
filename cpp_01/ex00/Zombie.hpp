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
