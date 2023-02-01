#pragma once
#include "Form.hpp"
#include "iostream"

class Form;

class Bureaucrat
{
	private :
		std::string const name;
		int grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat();

		Bureaucrat &operator= (Bureaucrat const &old);
		int getGrade() const;
		std::string getName() const;
		void setGrade(int grade);
		void promote();
		void demote();
		void signForm(Form &form);
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream & operator<< (std::ostream &out, const Bureaucrat &obj);
