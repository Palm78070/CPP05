# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 23:54:23 by rthammat          #+#    #+#              #
#    Updated: 2023/06/18 18:44:24 by rthammat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./Form

CXX := c++

CXXFLAGS := -Wall -Werror -Wextra --std=c++98 -g

SRCS := main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp \

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf *.o *_shrubbery *.dSYM

fclean: clean
	rm -rf $(NAME)

re: fclean all
