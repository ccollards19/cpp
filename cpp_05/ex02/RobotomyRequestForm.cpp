#include "RobotomyRequestForm.hpp"
#include "iostream"

RobotomyRequestForm::RobotomyRequestForm ()
	: AForm("Shrubbery", 0, 145, 137), target("target")
{
	std::cout<<"RobotomyRequestForm Default Constructor"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (std::string n_target)
	: AForm("Shrubbery", 0, 145, 137), target(n_target)
{
	std::cout<<"RobotomyRequestForm Constructor"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const &old)
	: AForm(old), target(old.get_target())
{
	std::cout<<"RobotomyRequestForm copy Constructor"<<std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator= (RobotomyRequestForm const &old)
{
	return *this;
}

///////////////////////////////////////////////////////////

RobotomyRequestForm::~RobotomyRequestForm ()
{
	std::cout<<"RobotomyRequestForm destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

std::string RobotomyRequestForm::get_target() const
{
	return this->target;
} 

void RobotomyRequestForm::execute(Bureaucrat &bureaucrat) const
{
	int grade = bureaucrat.Bureaucrat::getGrade();
	if (!exec_check(bureaucrat))
		throw AForm::GradeTooLowException();
	else if (this->get_status())
	{
		std::cout<<"[drilling noizes]"<<std::endl;
        	srand (time(NULL));
        	if (rand() % 2)
			std::cout<<this->get_target() <<" has been robotomised"<<std::endl;
      }
}

std::ostream & operator<< (std::ostream &out, const RobotomyRequestForm &obj)
{
	if (obj.RobotomyRequestForm::get_status())
		out<<"signed ";
	else
		out<<"unsigned ";
	
	out<<obj.RobotomyRequestForm::get_name()<< " form with target "
	<<obj.RobotomyRequestForm::get_target()<<"needs grade "
	<<obj.RobotomyRequestForm::get_exec_grade()<<" to be executed and "
	<<obj.RobotomyRequestForm::get_sign_grade()<<" to be signed"
	<<std::endl;
	return out;
}

/////////////////////////////////////////////////////////////
