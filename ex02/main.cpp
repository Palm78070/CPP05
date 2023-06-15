/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:19 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/16 03:14:33 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void ft_signForm(const Bureaucrat &src, AForm &AForm)
{
	try
	{
		AForm.beSigned(src);
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "///////////////// Shrubbery Test //////////////" << std::endl;
	Bureaucrat Bob = Bureaucrat("Bob", 120);
	std::cout << Bob << std::endl;
	ShrubberyCreationForm shcf1 = ShrubberyCreationForm("Whitehouse");
	std::cout << "Form name: " << shcf1.getName() << " => Target: " << shcf1.getTarget() << std::endl;
	Bob.executeForm(shcf1);
	std::cout << "\nTest form boundary:" << std::endl;
	Bureaucrat Jim = Bureaucrat("Jim", 150);
	std::cout << Jim << std::endl;
	std::cout << "Jim try to execute form => ";
	Jim.executeForm(shcf1);
	std::cout << "\nTest deep copy:" << std::endl;
	std::cout << "Try copy to shcf2" << std::endl;
	ShrubberyCreationForm shcf2 = ShrubberyCreationForm(shcf1);
	std::cout << "Form name: " << shcf2.getName() << " => Target: " << shcf2.getTarget() << std::endl;
	Bob.executeForm(shcf1);
	std::cout << "///////////////////////////////////////////////////" << std::endl;

	return (0);
}
