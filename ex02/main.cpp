/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:19 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/18 20:34:39 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//void ft_signForm(const Bureaucrat &src, AForm &AForm)
//{
//	try
//	{
//		AForm.beSigned(src);
//	}
//	catch (AForm::GradeTooHighException &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//	catch (AForm::GradeTooLowException &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//}

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
	std::cout << "\n///////////////// Robotomy Test //////////////" << std::endl;
	Bureaucrat Tony = Bureaucrat("Tony", 1);
	std::cout << Tony << std::endl;
	RobotomyRequestForm rrf1 = RobotomyRequestForm("Robot1");
	std::cout << "Form name: " << rrf1.getName() << " => Target: " << rrf1.getTarget() << std::endl;
	srand((unsigned int)time(NULL));
	Tony.executeForm(rrf1);
	Tony.executeForm(rrf1);
	Tony.executeForm(rrf1);
	std::cout << "\nTest form boundary:" << std::endl;
	std::cout << Bob << std::endl;
	std::cout << "Bob try to execute form => ";
	srand((unsigned int)time(NULL));
	Bob.executeForm(rrf1);
	std::cout << "\nTest deep copy:" << std::endl;
	std::cout << "Try copy to rrf2" << std::endl;
	RobotomyRequestForm rrf2 = RobotomyRequestForm(rrf1);
	std::cout << "Form name: " << rrf2.getName() << " => Target: " << rrf2.getTarget() << std::endl;
	Tony.executeForm(rrf2);
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << "\n///////////////// PresidentialPadon Test //////////////" << std::endl;
	Bureaucrat president = Bureaucrat("President", 1);
	std::cout << president << std::endl;
	PresidentialPardonForm ppf1 = PresidentialPardonForm("PardonForm1");
	std::cout << "Form name: " << ppf1.getName() << " => Target: " << ppf1.getTarget() << std::endl;
	president.executeForm(ppf1);
	std::cout << "\nTest form boundary:" << std::endl;
	std::cout << "Bob try to execute form => ";
	Bob.executeForm(ppf1);
	std::cout << "\nTry copy to ppf2" << std::endl;
	PresidentialPardonForm ppf2 = PresidentialPardonForm(ppf1);
	std::cout << "Form name: " << ppf2.getName() << " => Target: " << ppf2.getTarget() << std::endl;
	president.executeForm(ppf2);
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	return (0);
}
