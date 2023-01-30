#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	std::string target;
	public :
		RobotomyRequestForm(); 
		RobotomyRequestForm(std::string target); 
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator= (RobotomyRequestForm const &old);
		
		void execute(Bureaucrat &bureaucrat) const;
		std::string get_target() const;

};

std::ostream & operator<< (std::ostream &out, const RobotomyRequestForm &obj);
