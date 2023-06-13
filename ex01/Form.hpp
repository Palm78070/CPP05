/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:57:34 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/13 21:57:39 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bereaucrat.hpp"

class	Form
{
	public:
		Form(const Bereaucrat &src, int gradeSign, int gradeExec);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		void	beSigned(const Bereaucrat &src);

	private:
		const std::string	_name;
		boolean	_isSigned;
		const int	_gradeSign;
		const int	_gradeExec;
};

#endif
