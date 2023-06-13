/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bereaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:01:01 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/13 21:58:08 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BEREAUCRAT_H
#define BEREAUCRAT_H

#include <iostream>

class Bereaucrat
{
public:
	Bereaucrat(const std::string &name, int grade);
	Bereaucrat(const Bereaucrat &src);
	Bereaucrat &operator=(const Bereaucrat &src);
	~Bereaucrat();

	void GradeTooHighException(void);
	void GradeTooLowException(void);
	const std::string getName(void) const;
	int getGrade(void) const;
	void increaseGrade(void);
	void decreaseGrade(void);
	void signForm(const Form &src);

private:
	const std::string &_name;
	int _grade;
};
std::ostream &operator<<(std::ostream &output, const Bereaucrat &src);

#endif
