# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 23:54:23 by rthammat          #+#    #+#              #
#    Updated: 2023/06/13 02:22:44 by rthammat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./Bereaucrat

CXX := c++

CXXFLAGS := -Wall -Werror -Wextra --std=c++98 -g

SRCS := main.cpp \
	Bereaucrat.cpp \

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
