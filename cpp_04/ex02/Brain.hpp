#pragma once
#include <iostream>

class Brain
{
	std::string ideas[100];
	public :
		Brain ();
		Brain (const Brain &old);
		Brain &operator= (const Brain &old);
		~Brain ();
};
