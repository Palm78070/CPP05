/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bereaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:13 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/13 20:06:04 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bereaucrat.hpp"

Bereaucrat::Bereaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (!(this->_grade >= 1 && this->_grade <= 150))
			throw this->_grade;
	}
	catch (int grade)
	{
		if (grade < 1)
			Bereaucrat::GradeTooHighException();
		else if (grade > 150)
			Bereaucrat::GradeTooLowException();
	}
	std::cout << "Bereaucrat name " << this->_name << " is constructed" << std::endl;
}

Bereaucrat::~Bereaucrat(void)
{
	std::cout << "Bereaucrat name " << this->_name << " is destructed" << std::endl;
}

Bereaucrat::Bereaucrat(const Bereaucrat &src) : _name(src._name), _grade(src._grade)
{
	*this = src;
}

Bereaucrat &Bereaucrat::operator=(const Bereaucrat &src)
{
	std::cout << "Use operator overload=" << std::endl;
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	return (*this);
}

const std::string Bereaucrat::getName(void) const
{
	return (this->_name);
}

int Bereaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bereaucrat::GradeTooHighException(void)
{
	std::cout << "Grade of " << this->_name << " is too high" << std::endl;
}

void Bereaucrat::GradeTooLowException(void)
{
	std::cout << "Grade of " << this->_name << " is too Low" << std::endl;
}

void Bereaucrat::increaseGrade(void)
{
	int	grade;

	grade = this->getGrade() - 1;
	std::cout << "Try to increase grade of " << this->_name << std::endl;
	try
	{
		if (!(grade >= 1 && grade <= 150))
			throw grade;
		else
			this->_grade -= 1;
	}
	catch (int grade)
	{
		std::cout << "Cannot increase grade => ";
		if (grade < 1)
			Bereaucrat::GradeTooHighException();
		else if (grade > 150)
			Bereaucrat::GradeTooLowException();
	}
}

void Bereaucrat::decreaseGrade(void)
{
	int	grade;

	grade = this->getGrade() + 1;
	std::cout << "Try to decrease grade of " << this->_name << std::endl;
	try
	{
		if (!(grade + 1 >= 1 && grade + 1 <= 150))
			throw grade;
		else
			this->_grade += 1;
	}
	catch (int grade)
	{
		std::cout << "Cannot decrease grade =>";
		if (grade < 1)
			Bereaucrat::GradeTooHighException();
		else if (grade > 150)
			Bereaucrat::GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &output, const Bereaucrat &src)
{
	output << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (output);
}

