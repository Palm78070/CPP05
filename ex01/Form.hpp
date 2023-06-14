/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:57:34 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/14 20:55:30 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:
		Form(const std::string &name, int gradeSign, int gradeExec);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		const std::string getName(void) const;
		int getGradeSign(void) const;
		int getGradeExec(void) const;
		bool getSignStatus(void) const;
		void beSigned(const Bureaucrat &src);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Grade is too low");
			}
	};

	private:
		const std::string	_name;
		bool	_isSigned;
		const int	_gradeSign;
		const int	_gradeExec;
};
std::ostream &operator<<(std::ostream &output, const Form &src);

#endif
