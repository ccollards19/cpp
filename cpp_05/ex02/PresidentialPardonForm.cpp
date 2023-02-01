#include "PresidentialPardonForm.hpp"
#include "iostream"

PresidentialPardonForm::PresidentialPardonForm ()
	: AForm("Shrubbery", 0, 145, 137), target("target")
{
	std::cout<<"PresidentialPardonForm Default Constructor"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (std::string n_target)
	: AForm("Shrubbery", 0, 145, 137), target(n_target)
{
	std::cout<<"PresidentialPardonForm Constructor"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (PresidentialPardonForm const &old)
	: AForm(old), target(old.get_target())
{
	std::cout<<"PresidentialPardonForm copy Constructor"<<std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator= (PresidentialPardonForm const &old)
{
	return *this;
}

///////////////////////////////////////////////////////////

PresidentialPardonForm::~PresidentialPardonForm ()
{
	std::cout<<"PresidentialPardonForm destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

std::string PresidentialPardonForm::get_target() const
{
	return this->target;
} 

void PresidentialPardonForm::execute(Bureaucrat &bureaucrat) const
{
	int grade = bureaucrat.Bureaucrat::getGrade();
	if (!exec_check(bureaucrat))
		throw AForm::GradeTooLowException();
	else if (this->get_status())
		std::cout<<this->get_target() <<"has been pardoned by Zaphod Beeblebrox"<<std::endl;
	else
		std::cout<<"form couldn't be executed"<<std::endl;
}


std::ostream & operator<< (std::ostream &out, const PresidentialPardonForm &obj)
{
	if (obj.PresidentialPardonForm::get_status())
		out<<"signed ";
	else
		out<<"unsigned ";
	
	out<<obj.PresidentialPardonForm::get_name()<< " form with target "
	<<obj.PresidentialPardonForm::get_target()<<"needs grade "
	<<obj.PresidentialPardonForm::get_exec_grade()<<" to be executed and "
	<<obj.PresidentialPardonForm::get_sign_grade()<<" to be signed"
	<<std::endl;
	return out;
}

