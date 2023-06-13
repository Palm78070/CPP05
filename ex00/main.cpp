/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:19 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/14 01:07:02 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	ft_increase(Bureaucrat &src)
{
	try
	{
		src.increaseGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cout << e.what() << std::endl;
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	ft_decrease(Bureaucrat &src)
{
	try
	{
		src.decreaseGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cout << e.what() << std::endl;
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::cout << "///////////////// Increase grade Test //////////////" << std::endl;
	Bureaucrat Bob("Bob", 1);
    std::cout << Bob << std::endl;
	ft_increase(Bob);
	std::cout << "//////////////////////////////////////////////////\n" << std::endl;
	std::cout << "///////////////// Decrease grade Test //////////////" << std::endl;
	Bureaucrat John("John", 150);
    std::cout << John << std::endl;
	ft_decrease(John);
	std::cout << "//////////////////////////////////////////////////\n" << std::endl;
	std::cout << "///////////////// Normal case Test //////////////" << std::endl;
	std::cout << Bob << std::endl;
	ft_decrease(Bob);
	std::cout << Bob << std::endl;
	std::cout << "\n";
	std::cout << John << std::endl;
	ft_increase(John);
	std::cout << John << std::endl;
	std::cout << "//////////////////////////////////////////////////\n" << std::endl;
	return (0);
}
