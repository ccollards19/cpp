#include "ShrubberyCreationForm.hpp"
#include "iostream"

ShrubberyCreationForm::ShrubberyCreationForm ()
	: AForm("Shrubbery", 0, 145, 137), target("target")
{
	std::cout<<"ShrubberyCreationForm Default Constructor"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (std::string n_target)
	: AForm("Shrubbery", 0, 145, 137), target(n_target)
{
	std::cout<<"ShrubberyCreationForm Constructor"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm const &old)
	: AForm(old), target(old.get_target())
{
	std::cout<<"ShrubberyCreationForm copy Constructor"<<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (ShrubberyCreationForm const &old)
{
	return *this;
}

///////////////////////////////////////////////////////////

ShrubberyCreationForm::~ShrubberyCreationForm ()
{
	std::cout<<"ShrubberyCreationForm destructor"<<std::endl;
}
///////////////////////////////////////////////////////////

std::string ShrubberyCreationForm::get_target() const
{
	return this->target;
} 

// append ? TODO
static void make_trees(std::string target)
{
	std::ofstream dest(target+"_shrubberry");
	dest<<"                                                         ."<<std::endl;
	dest<<"                                      .         ;  "<<std::endl;
	dest<<"         .              .              ;%     ;;   "<<std::endl;
	dest<<"           ,           ,                :;%  %;   "<<std::endl;
	dest<<"            :         ;                   :;%;'     .,   "<<std::endl;
	dest<<"   ,.        %;     %;            ;        %;'    ,;"<<std::endl;
	dest<<"     ;       ;%;  %%;        ,     %;    ;%;    ,%'"<<std::endl;
	dest<<"      %;       %;%;      ,  ;       %;  ;%;   ,%;' "<<std::endl;
	dest<<"       ;%;      %;        ;%;        % ;%;  ,%;'"<<std::endl;
	dest<<"        `%;.     ;%;     %;'         `;%%;.%;'"<<std::endl;
	dest<<"         `:;%.    ;%%. %@;        %; ;@%;%'"<<std::endl;
	dest<<"            `:%;.  :;bd%;          %;@%;'"<<std::endl;
	dest<<"              `@%:.  :;%.         ;@@%;'   "<<std::endl;
	dest<<"                `@%.  `;@%.      ;@@%;         "<<std::endl;
	dest<<"                  `@%%. `@%%    ;@@%;        "<<std::endl;
	dest<<"                    ;@%. :@%%  %@@%;       "<<std::endl;
	dest<<"                      %@bd%%%bd%%:;     "<<std::endl;
	dest<<"                        #@%%%%%:;;"<<std::endl;
	dest<<"                        %@@%%%::;"<<std::endl;
	dest<<"                        %@@@%(o);  . '         "<<std::endl;
	dest<<"                        %@@@o%;:(.,'         "<<std::endl;
	dest<<"                    `.. %@@@o%::;         "<<std::endl;
	dest<<"                       `)@@@o%::;         "<<std::endl;
	dest<<"                        %@@(o)::;        "<<std::endl;
	dest<<"                       .%@@@@%::;         "<<std::endl;
	dest<<"                       ;%@@@@%::;.          "<<std::endl;
	dest<<"                      ;%@@@@%%:;;;. "<<std::endl;
	dest<<"                  ...;%@@@@@%%:;;;;,.. "<<std::endl;
	dest.std::ofstream::close();
}

void ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) const
{
	int grade = bureaucrat.Bureaucrat::getGrade();
	if (!exec_check(bureaucrat))
		throw AForm::GradeTooLowException();
	else if (this->get_status())
	{
		make_trees(this->target);
		std::cout<<"form is signed"<<std::endl;
	}
}


std::ostream & operator<< (std::ostream &out, const ShrubberyCreationForm &obj)
{
	if (obj.ShrubberyCreationForm::get_status())
		out<<"signed ";
	else
		out<<"unsigned ";
	
	out<<obj.ShrubberyCreationForm::get_name()<< " form with target "
	<<obj.ShrubberyCreationForm::get_target()<<"needs grade "
	<<obj.ShrubberyCreationForm::get_exec_grade()<<" to be executed and "
	<<obj.ShrubberyCreationForm::get_sign_grade()<<" to be signed"
	<<std::endl;
	return out;
}
