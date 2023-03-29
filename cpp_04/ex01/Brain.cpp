#include "Brain.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Brain::Brain ()
{
	std::cout<<"Brain Default Constructor"<<std::endl;
	int random_variable = std::rand();
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = random_variable % 26 + 'A';
		std::cout<<"IDEA :"<<ideas[i]<<"|||AT ADRR :"<<&ideas[i]<<std::endl;
	}
	std::cout<<"//////////Brain Constructed////////////////"<<std::endl;
	
}

Brain::Brain(const Brain &old)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = (old.ideas)[i];
}

Brain &Brain::operator= (const Brain &old)
{
	if (&old != this)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = (old.ideas)[i];
	}
	return *this;
}

///////////////////////////////////////////////////////////

Brain::~Brain ()
{
	std::cout<<"Brain destructor"<<std::endl;
	for (int i = 0; i < 100; i++)
		std::cout<<"IDEA : "<<ideas[i]<<" ||| AT ADRR :"<<&ideas[i]<<std::endl;
	std::cout<<"//////////Brain Destructed////////////////"<<std::endl;
}
///////////////////////////////////////////////////////////
