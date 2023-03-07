#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	int myints[] = {1,2,2,4,5};
	int i;
	{
		std::cout<<"test with vectors"<<std::endl;
		std::vector<int> vec(myints, &(myints[5]));
		for (i = 0; i < vec.size(); i++)	
			std::cout<<vec[i]<<", ";
		std::cout<<std::endl;
		for (std::vector<int>::iterator it = easyfind(vec, 3); it != vec.end();it++)
			std::cout<<*it<<", ";
		std::cout<<std::endl;
	}
	{
		std::cout<<"same with list"<<std::endl;
		std::list<int> lst(myints, &(myints[5]));
		
		for (std::list<int>::iterator it = lst.begin(); it != lst.end();it++)
			std::cout<<*it<<", ";
		std::cout<<std::endl;
		for (std::list<int>::iterator it = easyfind(lst, 3); it != lst.end();it++)
			std::cout<<*it<<", ";
		std::cout<<std::endl;
	}
	return 0;
}
