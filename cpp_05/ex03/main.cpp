#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat franz("franz",  1);
	Bureaucrat underling(150);

	ShrubberyCreationForm form;
	ShrubberyCreationForm contract("test");
	
	underling.signForm(form);
	franz.signForm(form);
	std::cout<<form<<std::endl;
	
	underling.signForm(contract);
	franz.signForm(contract);
	franz.executeForm(contract);
	std::cout<<contract<<std::endl;
	
	std::cout<<underling<<franz;
}
