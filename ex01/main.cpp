/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 02:22:19 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/13 21:20:25 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bereaucrat.hpp"

int main(void)
{
	std::cout << "/////////////////// Basic Test /////////////////\n" << std::endl;
	Bereaucrat Bob("Bob", 1);
	std::cout << Bob;
	std::cout << "\n////////////////////////////////////////////////\n" << std::endl;
	std::cout << "///////////////// Increase grade Test //////////////\n" << std::endl;
	Bob.increaseGrade();
	std::cout << Bob;
	std::cout << "\n//////////////////////////////////////////////////\n" << std::endl;
	std::cout << "///////////////// decrease grade Test //////////////\n " << std::endl;
	Bob.decreaseGrade();
	std::cout << Bob;
	std::cout << "\n//////////////////////////////////////////////////\n" << std::endl;
	std::cout << "///////////////// Increase grade Test //////////////\n" << std::endl;
	Bob.increaseGrade();
	std::cout << Bob;
	std::cout << "\n//////////////////////////////////////////////////\n" << std::endl;
	std::cout << "///////////////////// Deep copy Test /////////////////\n" << std::endl;
	Bereaucrat Bob2 = Bereaucrat(Bob);
	std::cout << "This is Bob2 => ";
	std::cout << Bob2;
	std::cout << "decrease grade of Bob2 => ";
	Bob2.decreaseGrade();
	std::cout << "Check grade of Bob2 => ";
	std::cout << Bob2;
	std::cout << "Check grade of original Bob => ";
	std::cout << Bob;
	std::cout << "decrease grade of original Bob => ";
	Bob.decreaseGrade();
	Bob.decreaseGrade();
	Bob.decreaseGrade();
	std::cout << "Check grade of original Bob => ";
	std::cout << Bob;
	std::cout << "Check grade of Bob2 => ";
	std::cout << Bob2;
	std::cout << "\n////////////////////////////////////////////////////\n" << std::endl;
	std::cout << "///////////////// Decrease grade Test //////////////\n" << std::endl;
	while (Bob.getGrade() < 149)
		Bob.decreaseGrade();
	Bob.decreaseGrade();
	std::cout << Bob;
	Bob.decreaseGrade();
	std::cout << "\n//////////////////////////////////////////////////\n" << std::endl;
	return (0);
}
