#include <iostream>
#include "header.hpp"

void f(int &arg)
{
	std::cout<<arg<<std::endl;
}

int main( void ) 
{
	int tab[] = { 1, 2, 3, 4, 5};

	iter(tab, 5, &f);
	return 0;
}
