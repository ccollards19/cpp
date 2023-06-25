#include "AForm.hpp"
#include "iostream"

AForm::AForm ()
	: name("default"), is_signed(0), sign_grade(150), exec_grade(150)
{
	std::cout<<"AForm Default Constructor"<<std::endl;
}

AForm::AForm (std::string n_name, bool n_is_signed, int n_sign_grade, int n_exec_grade)
	: name(n_name), is_signed(n_is_signed), sign_grade(n_sign_grade), exec_grade(n_exec_grade)
{
	std::cout<<"AForm Constructor"<<std::endl;
}

AForm::AForm (AForm const &old)
	: name(old.AForm::get_name()), 
	is_signed(old.AForm::get_status()), 
	sign_grade(old.AForm::get_exec_grade()), 
	exec_grade(old.AForm::get_exec_grade())
{
	std::cout<<"AForm copy Constructor"<<std::endl;
}

AForm &AForm::operator= (AForm const &old)
{
	is_signed = old.get_status();
	return *this;
}

///////////////////////////////////////////////////////////

AForm::~AForm ()
{
	std::cout<<"AForm destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	int grade = bureaucrat.Bureaucrat::getGrade();
	if (grade > 150)
		throw AForm::GradeTooLowException();
	else if (grade < 1)
		throw AForm::GradeTooHighException();
	else if (grade > this->get_sign_grade())
		throw AForm::GradeTooLowException();
	else
	{
		this->is_signed = 1;
		std::cout<<"form is signed"<<std::endl;
	}
}

std::string AForm::get_name() const
{
	return this->name;
} 

int AForm::get_sign_grade() const
{
	return this->sign_grade;
}

int AForm::get_exec_grade() const
{
	return this->exec_grade;
}

bool AForm::get_status() const
{
	return this->is_signed;
}

bool AForm::exec_check(Bureaucrat &bureaucrat) const
{
	return (this->exec_grade >= bureaucrat.Bureaucrat::getGrade());
}

/////////////////////////////////////////////////////////////

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}
