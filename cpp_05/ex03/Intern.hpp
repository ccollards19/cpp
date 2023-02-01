#pragma once
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern &obj);
		~Intern();

		Intern &operator= (Intern const &old);
		AForm *makeForm(std::string type, std::string target);		
};

