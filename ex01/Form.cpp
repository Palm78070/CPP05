#include "Form.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	try
	{
		if (!(this->_gradeSign >= 1 && this->_gradeSign <= 150))
			throw this->_gradeSign;
	}
	catch (int grade)
	{
		if (grade < 1)
			Form::GradeTooHighException();
		else if (grade > 150)
			Form::GradeTooLowException();
	}
	this->_isSigned = 0;
	std::cout << "Form of " << this->_name << " is constructed" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()), _gradeSign(src.getGradeSign()), _gradeExec(getGradeExec())
{
	*this = src;
}

Form::~Form(void)
{
	std::cout << "Form of " << this->_name << " is destructed" << std::endl;
}

void Form::GradeTooHighException(void)
{
	std::cout << "Grade to sign form of " << this->_name << " is out of bound => too high" << std::endl;
}

void Form::GradeTooLowException(void)
{
	std::cout << "Grade to sign form of " << this->_name << " is out of bound => too low" << std::endl;
}
