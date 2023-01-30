#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	std::string const name;
	bool is_signed;
	int const sign_grade;
	int const exec_grade;
	public :
		Form();
		Form(std::string name, bool is_signed, int sign_grade, int exec_grade);
		Form(const Form &obj);
		~Form();

		Form &operator= (Form const &old);
		
		std::string get_name() const;
		bool get_status() const;
		int get_sign_grade() const;
		int get_exec_grade() const;
		
		void beSigned(Bureaucrat &bureaucrat);

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

std::ostream & operator<< (std::ostream &out, const Form &obj);
