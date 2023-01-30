#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
	Bureaucrat franz("franz",  1);
	Bureaucrat underling(150);

	Form form;
	Form contract("contract", 0, 1, 1);
	
	underling.signForm(form);
	franz.signForm(form);
	std::cout<<form<<std::endl;
	
	underling.signForm(contract);
	franz.signForm(contract);
	std::cout<<contract<<std::endl;
	
	std::cout<<underling<<franz;
}
