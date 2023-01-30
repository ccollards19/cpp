#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat ()
	: name("underling"), grade(150)
{
	std::cout<<"Bureaucrat Default Constructor"<<std::endl;
}

Bureaucrat::Bureaucrat (std::string nname, int ngrade)
	: name(nname)
{
	setGrade(ngrade);
	std::cout<<"Bureaucrat Constructor"<<std::endl;
}

Bureaucrat::Bureaucrat (std::string nname)
	: name(nname), grade(150)
{
	std::cout<<"Bureaucrat Constructor"<<std::endl;
}

Bureaucrat::Bureaucrat (int ngrade)
	: name("underling")
{
	setGrade(ngrade);
	std::cout<<"Bureaucrat Constructor"<<std::endl;
}

Bureaucrat::Bureaucrat (Bureaucrat const &old)
	: name(old.Bureaucrat::getName())
{
	this->setGrade(old.Bureaucrat::getGrade());
	std::cout<<"Bureaucrat copy Constructor"<<std::endl;
}

Bureaucrat &Bureaucrat::operator= (Bureaucrat const &old)
{
	return *this;
}
///////////////////////////////////////////////////////////

Bureaucrat::~Bureaucrat ()
{
	std::cout<<"Bureaucrat destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		this->grade = grade;
	}
	catch (std::exception &err)
	{
		std::cerr<<err.what()<<std::endl;
	}
}

void Bureaucrat::promote()
{
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::demote()
{
	this->setGrade(this->getGrade() + 1);
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.Form::beSigned(*this);
		std::cout<<this->getName()<<" signed form "<< form.Form::get_name()<<std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr<<this->Bureaucrat::getName()<<" couldn't sign "
		<<form.Form::get_name()<<" because "
		<<err.what()<<std::endl;
	}
}

///////////////////////////////////////////////////

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

///////////////////////////////////////////////////

std::ostream & operator<< (std::ostream &out, const Bureaucrat &obj)
{
	out<<obj.Bureaucrat::getName()<<", bureaucrat grade "<<obj.Bureaucrat::getGrade()<<std::endl;
	return out;
}
