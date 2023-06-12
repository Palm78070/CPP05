/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bereaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:01:01 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/13 02:08:27 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef BEREAUCRAT_H
#define BEREAUCRAT_H

class Bereaucrat
{
public:
	Bereaucrat(const std::string &name, int grade);
	Bereaucrat(const Bereaucrat &src);
	Bereaucrat &operator=(const Bereaucrat &src);
	~Bereaucrat();

	void GradeTooHighException();
	void GradeTooLowException();
	const std::string getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();

private:
	const std::string &_name;
	int _grade;
};
std::ostream &operator<<(std::ostream &output, const Bereaucrat &src);

#endif
