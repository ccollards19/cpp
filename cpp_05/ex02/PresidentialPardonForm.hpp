#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	std::string target;
	public :
		PresidentialPardonForm(); 
		PresidentialPardonForm(std::string target); 
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator= (PresidentialPardonForm const &old);
		
		void execute(Bureaucrat &bureaucrat) const;
		std::string get_target() const;

};

std::ostream & operator<< (std::ostream &out, const PresidentialPardonForm &obj);
