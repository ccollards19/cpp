#pragma once
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	std::string const name;
	bool is_signed;
	int const sign_grade;
	int const exec_grade;
	public :
		AForm();
		AForm(std::string name, bool is_signed, int sign_grade, int exec_grade);
		AForm(const AForm &obj);
		~AForm();

		AForm &operator= (AForm const &old);
		
		std::string get_name() const;
		bool get_status() const;
		int get_sign_grade() const;
		int get_exec_grade() const;
		
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat &bureaucrat) const = 0;
		bool exec_check(Bureaucrat &bureaucrat) const;

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

