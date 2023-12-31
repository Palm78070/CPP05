/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:19 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/18 20:20:17 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "///////////////// Shrubbery Test //////////////" << std::endl;
	Bureaucrat Bob = Bureaucrat("Bob", 120);
	std::cout << Bob << std::endl;
	Intern someRandomIntern;
	AForm *shcf1 = someRandomIntern.makeForm("shrubbery creation", "Whitehouse");
	std::cout << "Form name: " << shcf1->getName() << " => Target: " << shcf1->getTarget() << std::endl;
	Bob.executeForm(*shcf1);
	if (shcf1)
		delete shcf1;
	std::cout << "\nTest Intern form name not match" << std::endl;
	AForm *shcf2 = someRandomIntern.makeForm("xxx", "Whitehouse");
	(void)shcf2;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << "\n///////////////// Robotomy Test //////////////" << std::endl;
	Bureaucrat Tony = Bureaucrat("Tony", 1);
	std::cout << Tony << std::endl;
	//Intern someRandomIntern2;
	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << "Form name: " << rrf->getName() << " => Target: " << rrf->getTarget() << std::endl;
	Tony.executeForm(*rrf);
	if (rrf)
		delete rrf;
	std::cout << "\nTest Intern form name not match" << std::endl;
	AForm *rrf2 = someRandomIntern.makeForm("abc", "Bender");
	(void)rrf2;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << "\n///////////////// PresidentialPadon Test //////////////" << std::endl;
	Bureaucrat president = Bureaucrat("President", 1);
	std::cout << president << std::endl;
	//Intern someRandomIntern3;
	AForm *ppf1 = someRandomIntern.makeForm("presidential pardon", "Pardon1");
	std::cout << "Form name: " << ppf1->getName() << " => Target: " << ppf1->getTarget() << std::endl;
	president.executeForm(*ppf1);
	delete ppf1;
	std::cout << "\nTest Intern form name not match" << std::endl;
	AForm *ppf2 = someRandomIntern.makeForm("123", "Pardon1");
	(void)ppf2;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	return (0);
}
