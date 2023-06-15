#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm: " << _target << " is constructed" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm: " << _target << " is destructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137), _target(src.getTarget())
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	(void)src;
	return (*this);
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	std::ofstream file (this->getTarget() + "_shrubbery");
	file << "         ###         " << std::endl;
	file << "        #o###        " << std::endl;
	file << "      #####o###      " << std::endl;
	file << "     #o###|#/###     "<< std::endl;
	file << "      ####|##o#      "<< std::endl;
	file << "       # }|{  #      "<< std::endl;
	file << "         }|{         "<< std::endl;
	file.close();
}
