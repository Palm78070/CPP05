/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:33:52 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/16 02:22:23 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (this->getGradeSign() < 1 || this->getGradeExec() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getGradeSign() > 150 || this->getGradeExec() > 150)
		throw AForm::GradeTooLowException();
	this->_isSigned = 0;
	std::cout << "AForm of " << this->_name << " is constructed" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src.getName()), _isSigned(src.getSignStatus()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	*this = src;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		this->_isSigned = src.getSignStatus();
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm of " << this->_name << " is destructed" << std::endl;
}

const std::string AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

bool AForm::getSignStatus(void) const
{
	return (this->_isSigned);
}

void AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= this->getGradeSign())
		this->_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output, const AForm &src)
{
	output << "Form name: " << src.getName() << std::endl;
	output << "Grade sign: " << src.getGradeSign() << std::endl;
	output << "Grade execute: " << src.getGradeExec() << std::endl;
	output << "Signed status: ";
	if (src.getSignStatus() == true)
		output << "Signed";
	else
		output << "Not signed";
	return (output);
}
