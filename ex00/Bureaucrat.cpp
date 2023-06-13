/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:13 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/14 00:04:40 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat name " << this->_name << " is constructed" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat name " << this->_name << " is destructed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Use operator overload=" << std::endl;
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	return (*this);
}

const std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::increaseGrade(void)
{
	int	grade;

	grade = this->getGrade() - 1;
	std::cout << "Try to increase grade of " << this->_name << std::endl;
	//try
	//{
	//	if (!(grade >= 1 && grade <= 150))
	//		throw grade;
	//	else
	//		this->_grade -= 1;
	//}
	//catch (int grade)
	//{
	//	std::cout << "Cannot increase grade => ";
	//	if (grade < 1)
	//		Bureaucrat::GradeTooHighException();
	//	else if (grade > 150)
	//		Bureaucrat::GradeTooLowException();
	//}
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decreaseGrade(void)
{
	int	grade;

	grade = this->getGrade() + 1;
	std::cout << "Try to decrease grade of " << this->_name << std::endl;
	//try
	//{
	//	if (!(grade >= 1 && grade <= 150))
	//		throw grade;
	//	else
	//		this->_grade += 1;
	//}
	//catch (int grade)
	//{
	//	std::cout << "Cannot decrease grade =>";
	//	if (grade < 1)
	//		Bureaucrat::GradeTooHighException();
	//	else if (grade > 150)
	//		Bureaucrat::GradeTooLowException();
	//}
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &src)
{
	output << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (output);
}

