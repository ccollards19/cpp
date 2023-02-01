#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat franz("franz",  1);
	Bureaucrat underling(150);
	Intern intern;

	AForm *form = intern.makeForm("shrubbery creation", "intern_test");
	
	underling.signForm(*form);
	franz.signForm(*form);

	underling.executeForm(*form);
	franz.executeForm(*form);
//	std::cout<<(*form)<<std::endl;
	
	std::cout<<underling<<franz;
}
