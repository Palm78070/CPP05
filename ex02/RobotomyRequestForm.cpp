#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm: " << _target << " is constructed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm: " << _target << " is destructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	(void)src;
	return (*this);
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
}
