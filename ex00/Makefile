# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 10:29:59 by jweber            #+#    #+#              #
#    Updated: 2026/01/05 10:32:27 by jweber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := megaphone

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std="c++98" 

CXX_FILES := megaphone.cpp
CXX_OBJ := $(CXX_FILES:.cpp=.o)

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(CXX_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o:%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	rm -f $(CXX_OBJ)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
