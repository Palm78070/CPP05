/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:33:41 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/15 18:33:44 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	public:
		AForm(const std::string &name, int gradeSign, int gradeExec);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		const std::string getName(void) const;
		int getGradeSign(void) const;
		int getGradeExec(void) const;
		bool getSignStatus(void) const;
		void beSigned(const Bureaucrat &src);
		virtual void execute(Bureaucrat const &executor) const = 0;

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
std::ostream &operator<<(std::ostream &output, const AForm &src);

#endif
