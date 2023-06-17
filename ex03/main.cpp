/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:19 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/17 19:18:58 by rthammat         ###   ########.fr       */
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
	Intern someRandomIntern1;
	AForm *shcf1 = someRandomIntern1.makeForm("shrubbery creation", "Whitehouse");
	std::cout << "Form name: " << shcf1->getName() << " => Target: " << shcf1->getTarget() << std::endl;
	Bob.executeForm(*shcf1);
	std::cout << "\nTest Intern form name not match" << std::endl;
	AForm *shcf2 = someRandomIntern1.makeForm("xxx", "Whitehouse");
	(void)shcf2;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << "\n///////////////// Robotomy Test //////////////" << std::endl;
	Bureaucrat Tony = Bureaucrat("Tony", 1);
	std::cout << Tony << std::endl;
	Intern someRandomIntern2;
	AForm *rrf = someRandomIntern2.makeForm("robotomy request", "Bender");
	std::cout << "Form name: " << rrf->getName() << " => Target: " << rrf->getTarget() << std::endl;
	Tony.executeForm(*rrf);
	std::cout << "\nTest Intern form name not match" << std::endl;
	AForm *rrf2 = someRandomIntern2.makeForm("abc", "Bender");
	(void)rrf2;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << "\n///////////////// PresidentialPadon Test //////////////" << std::endl;
	Bureaucrat president = Bureaucrat("President", 1);
	std::cout << president << std::endl;
	Intern someRandomIntern3;
	AForm *ppf1 = someRandomIntern3.makeForm("presidential pardon", "Pardon1");
	std::cout << "Form name: " << ppf1->getName() << " => Target: " << ppf1->getTarget() << std::endl;
	president.executeForm(*ppf1);
	std::cout << "\nTest Intern form name not match" << std::endl;
	AForm *ppf2 = someRandomIntern3.makeForm("123", "Pardon1");
	(void)ppf2;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	return (0);
}
