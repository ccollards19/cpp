#include "Intern.hpp"

Intern::Intern ()
{
	std::cout<<"Intern Default Constructor"<<std::endl;
}

Intern::Intern (Intern const &old)
{
	std::cout<<"Intern copy Constructor"<<std::endl;
}

Intern &Intern::operator= (Intern const &old)
{
	return *this;
}

///////////////////////////////////////////////////////////

Intern::~Intern ()
{
	std::cout<<"Intern destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

AForm *Intern::makeForm(std::string type, std::string target)
{
	AForm *ret = NULL;
	((target.compare("shrubbery creation") && (ret = new ShrubberyCreationForm(target))) ||
	(target.compare("robotomy request") && (ret = new RobotomyRequestForm(target))) ||
	(target.compare("presidential pardon") && (ret = new PresidentialPardonForm(target))) ||
	std::cerr<<"Intern couldn't make form"<<std::endl);
	return ret;
}
