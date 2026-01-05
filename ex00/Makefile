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

CC := c++
CFLAGS := -Wall -Wextra -Werror -std="c++98" 

CPP_FILES := megaphone.cpp

all: $(NAME)

$(NAME): $(CPP_FILES)
	$(CC) $(CFLAGS) $^ -o $@
