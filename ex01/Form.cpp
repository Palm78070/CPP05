/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:08:12 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/14 22:08:13 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (this->getGradeSign() < 1 || this->getGradeExec() < 1)
		throw Form::GradeTooHighException();
	else if (this->getGradeSign() > 150 || this->getGradeExec() > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = 0;
	std::cout << "Form of " << this->_name << " is constructed" << std::endl;
}

Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.getSignStatus()), _gradeSign(src.getGradeSign()), _gradeExec(getGradeExec())
{
	*this = src;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		this->_isSigned = src.getSignStatus();
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form of " << this->_name << " is destructed" << std::endl;
}

const std::string Form::getName(void) const
{
	return (this->_name);
}

int Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

bool Form::getSignStatus(void) const
{
	return (this->_isSigned);
}

void Form::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() <= this->getGradeSign())
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output, const Form &src)
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
