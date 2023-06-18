/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 05:15:55 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/18 20:13:20 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	//this->_res = NULL;
	std::cout << "Intern is constructed" << std::endl;
}

Intern::~Intern()
{
	//if (this->_res)
	//{
	//	std::cout << "+++++ Clear memory of " << this->_res->getName() << " +++++" << std::endl;
	//	delete this->_res;
	//	this->_res = NULL;
	//}
	std::cout << "Intern is destructed" << std::endl;
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm *Intern::makeForm(const std::string &fname, const std::string &target)
{
	AForm *res = NULL;
	int match = 0;
	const AForm *type[3] = {new ShrubberyCreationForm(target),
							new RobotomyRequestForm(target),
							new PresidentialPardonForm(target)};
	try
	{
		int i = -1;
		while (++i < 3)
		{
			if (fname == type[i]->getName() && ++match)
			{
				//this->_res = (AForm *)type[i];
				res = (AForm *)type[i];
				continue;
			}
			delete type[i];
		}
		if (!match)
			throw Intern::FormNotExist();
	}
	catch (Intern::FormNotExist &e)
	{
		std::cout << e.what() << std::endl;
		return (NULL);
	}
	return (res);
}
