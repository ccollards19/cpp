#include <iostream>
#include <vector>
#include <list>
#include "Span.hpp"

//TODO add range test and huge range test

int main()
{
	int myints[] = {1,4,2,5,2,-10,20};
	int i;
	try
	{
		std::cout<<"test with vectors"<<std::endl;
		std::vector<int> vec(myints, &(myints[7]));
		Span obj(7);
		obj.addNumberRange(vec.begin(), vec.end());
		std::cout<<obj.shortestSpan()<<std::endl;
		std::cout<<obj.longestSpan()<<std::endl;
	}
	catch (const std::exception &err)
	{
		std::cout<<err.what()<<std::endl;
	}

	return 0;
}
