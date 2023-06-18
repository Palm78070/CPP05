#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy request", 72, 45), _target(target)
{
	//std::cout << "RobotomyRequestForm: " << _target << " is constructed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	//std::cout << "RobotomyRequestForm: " << _target << " is destructed" << std::endl;
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
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << "Bzzzzzz... => ";
	//srand((unsigned int)time(NULL));
	if (rand() % 2 != 0)
		std::cout
			<< this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
