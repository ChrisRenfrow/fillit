# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 09:42:52 by crenfrow          #+#    #+#              #
#    Updated: 2016/10/07 13:04:35 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit.exe
FILENAMES	= main.c	\

SOURCES 	= $(addprefix src/, $(FILENAMES))
BUILD 		= $(addprefix build/, $(FILENAMES:.c=.o))
LIBNAME 	= ft
LIBDIR 		= lib/
INCLUDES	= includes/
FLAGS 		= -Wall -Wextra -Werror #-fsanitize=address
CC 			= gcc

all: $(NAME)

$(NAME): $(SOURCES) | $(BUILD)
		$(CC) $(FLAGS) $(SOURCES) -I $(INCLUDES) -o $(NAME) -L$(LIBDIR) -l$(LIBNAME)

build/%.o: src/%.c | build
		$(CC) $(FLAGS) -I $(INCLUDES) -c $^ -o $@

clean:
		rm -rf build/

fclean: clean
		rm -rf $(NAME)

run: all
		./$(NAME)

re: fclean all

build:
		mkdir build/

.PHONY: all clean fclean re run norme
