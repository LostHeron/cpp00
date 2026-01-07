# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 10:29:59 by jweber            #+#    #+#              #
#    Updated: 2026/01/05 15:19:26 by jweber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phonebook

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std="c++98" -MMD -MP

CXX_FILES := main.cpp\
			 PhoneBook.cpp \
			 Contact.cpp \

CXX_OBJECTS_DIR := .obj/

CXX_OBJECTS_FILES := $(addprefix $(CXX_OBJECTS_DIR),$(CXX_FILES:.cpp=.o))

CXX_DEPS := $(CXX_OBJECTS_FILES:.o=.d)


all: $(NAME)

$(NAME): $(CXX_OBJECTS_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

-include $(CXX_DEPS)

$(CXX_OBJECTS_DIR)%.o : %.cpp | $(CXX_OBJECTS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CXX_OBJECTS_DIR):
	mkdir -p $@

clean:
	rm -rf $(CXX_OBJECTS_DIR)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
