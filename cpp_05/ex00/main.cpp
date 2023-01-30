#include "Bureaucrat.hpp"
#include <iostream>

int main() 
{
	Bureaucrat franz("franz",  1);
	Bureaucrat underling(150);
	franz.promote();	
	franz.demote();	
	underling.demote();	
	underling.promote();	
	std::cout<<underling<<franz;
}
