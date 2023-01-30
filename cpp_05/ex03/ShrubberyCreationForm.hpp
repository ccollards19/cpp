#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	std::string target;
	public :
		ShrubberyCreationForm(); 
		ShrubberyCreationForm(std::string target); 
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator= (ShrubberyCreationForm const &old);
		
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat &bureaucrat) const;
		std::string get_target() const;

};

std::ostream & operator<< (std::ostream &out, const ShrubberyCreationForm &obj);
