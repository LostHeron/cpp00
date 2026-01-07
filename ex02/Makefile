# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 09:02:25 by jweber            #+#    #+#              #
#    Updated: 2026/01/07 10:55:46 by jweber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := a.out
CXX := c++
CXXFLAGS := -std="c++98" -Wall -Wextra -Werror 

CXX_SOURCE_FILES := Account.cpp \
					tests.cpp \

OBJECTS_DIR := .obj/
OBJECTS_FILES := $(addprefix $(OBJECTS_DIR), $(CXX_SOURCE_FILES:.cpp=.o))

all: $(NAME)

$(NAME) : $(OBJECTS_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJECTS_DIR)%.o : %.cpp | $(OBJECTS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJECTS_DIR):
	mkdir -p $@

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJECTS_DIR)

fclean:
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
