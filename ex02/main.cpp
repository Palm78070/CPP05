/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:19 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/15 22:42:28 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	ft_signForm(const Bureaucrat &src, AForm &AForm)
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
	std::cout << "///////////////// Normal case Test //////////////" << std::endl;
	Bureaucrat Bob = Bureaucrat("Bob", 120);
	std::cout << Bob << std::endl;
	ShrubberyCreationForm shcf1 = ShrubberyCreationForm("Whitehouse");
	shcf1.getName();
	Bob.executeForm(shcf1);
	//AForm AForm1 = AForm("AForm1", 145, 137);
	//std::cout << AForm1 << std::endl;
	//Bob.signForm(AForm1);
	//std::cout << "Signed status after " << Bob.getName() << " sign AForm => " << AForm1.getSignStatus() << std::endl;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	//std::cout << "\n///////////////// Sign status Test //////////////" << std::endl;
	//Bureaucrat Ken = Bureaucrat("Ken", 150);
	//std::cout << Ken << std::endl;
	//AForm AForm2 = AForm("AForm2", 72, 45);
	//std::cout << AForm2 << std::endl;
	//Ken.signForm(AForm2);
	//std::cout << "///////////////////////////////////////////////////" << std::endl;
	//std::cout << "\n///////////////// Grade high/Low Test //////////////" << std::endl;
	//try
	//{
	//	AForm AFormOut1 = AForm("AFormOut1", 151, 10);
	//}
	//catch (AForm::GradeTooLowException &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//try
	//{
	//	AForm AFormOut2 = AForm("AFormOut2", 20, 0);
	//}
	//catch (AForm::GradeTooHighException &e)
	//{
	//	std::cout << e.what() << std::endl;
	//}
	//std::cout << "///////////////////////////////////////////////////" << std::endl;
	//std::cout << "\n///////////////// Deep Copy Test //////////////" << std::endl;
	//std::cout << AForm1 << std::endl;
	//std::cout << "\n";
	//AForm AFormCp = AForm(AForm1);
	//std::cout << AFormCp << std::endl;
	//std::cout << "///////////////////////////////////////////////////" << std::endl;
	return (0);
}
