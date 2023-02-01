#include "Form.hpp"
#include "iostream"

Form::Form ()
	: name("default"), is_signed(0), sign_grade(150), exec_grade(150)
{
	std::cout<<"Form Default Constructor"<<std::endl;
}

Form::Form (std::string n_name, bool n_is_signed, int n_sign_grade, int n_exec_grade)
	: name(n_name), is_signed(n_is_signed), sign_grade(n_sign_grade), exec_grade(n_exec_grade)
{
	std::cout<<"Form Constructor"<<std::endl;
}

Form::Form (Form const &old)
	: name(old.Form::get_name()), 
	is_signed(old.Form::get_status()), 
	sign_grade(old.Form::get_exec_grade()), 
	exec_grade(old.Form::get_exec_grade())
{
	std::cout<<"Form copy Constructor"<<std::endl;
}

Form &Form::operator= (Form const &old)
{
	return *this;
}

///////////////////////////////////////////////////////////

Form::~Form ()
{
	std::cout<<"Form destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

std::string Form::get_name() const
{
	return this->name;
} 

int Form::get_sign_grade() const
{
	return this->sign_grade;
}

int Form::get_exec_grade() const
{
	return this->exec_grade;
}

bool Form::get_status() const
{
	return this->is_signed;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	int grade = bureaucrat.Bureaucrat::getGrade();
	if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > this->get_sign_grade())
		throw Form::GradeTooLowException();
	else
	{
		this->is_signed = 1;
		std::cout<<"form is signed"<<std::endl;
	}
}

std::ostream & operator<< (std::ostream &out, const Form &obj)
{
	if (obj.Form::get_status())
		out<<"signed ";
	else
		out<<"unsigned ";
	out<<obj.Form::get_name()<< " form needs grade "
	<<obj.Form::get_exec_grade()<<" to be executed and "
	<<obj.Form::get_sign_grade()<<" to be signed"
	<<std::endl;
	return out;
}

/////////////////////////////////////////////////////////////

const char *Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}
