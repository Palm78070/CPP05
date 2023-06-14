/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:19 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/14 22:17:53 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	ft_signForm(const Bureaucrat &src, Form &form)
{
	try
	{
		form.beSigned(src);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "///////////////// Normal case Test //////////////" << std::endl;
	Bureaucrat Bob = Bureaucrat("Bob", 1);
	std::cout << Bob << std::endl;
	Form form1 = Form("Form1", 145, 137);
	std::cout << form1 << std::endl;
	Bob.signForm(form1);
	std::cout << "Signed status after " << Bob.getName() << " sign form => " << form1.getSignStatus() << std::endl;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << "\n///////////////// Sign status Test //////////////" << std::endl;
	Bureaucrat Ken = Bureaucrat("Ken", 150);
	std::cout << Ken << std::endl;
	Form form2 = Form("Form2", 72, 45);
	std::cout << form2 << std::endl;
	Ken.signForm(form2);
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << "\n///////////////// Grade high/Low Test //////////////" << std::endl;
	try
	{
		Form formOut1 = Form("FormOut1", 151, 10);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form formOut2 = Form("FormOut2", 20, 0);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << "\n///////////////// Deep Copy Test //////////////" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << "\n";
	Form formCp = Form(form1);
	std::cout << formCp << std::endl;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	return (0);
}
