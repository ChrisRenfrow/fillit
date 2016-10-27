# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/20 18:04:00 by crenfrow          #+#    #+#              #
#    Updated: 2016/10/26 19:10:37 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit
FILENAMES 	= 	main			\
				input_handler 	\
				validate_piece 	\
				map_maker		\
				map_check		\
				fit_pieces		\
				print_solution	\

CFILES		= $(addsuffix .c, $(FILENAMES))
SOURCES 	= $(addprefix src/, $(CFILES))
OBJECTS		= $(addprefix build/, $(CFILES:.c=.o))
LIBNAME		= ft
LIBDIR		= lib/
INCDIR		= includes/
FLAGS		= -Wall -Wextra -Werror #-fsanitize=address
CC			= gcc

$(NAME): $(SOURCES) | $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -I $(INCDIR) -L $(LIBDIR) -l $(LIBNAME) -o $(NAME)

build/%.o: src/%.c | build
	$(CC) $(FLAGS) -I $(INCDIR) -c $^ -o $@

rtest: $(NAME)
	time (python tests/rand_test.py 26 > tests/randtestMAX.txt && \
	./$(NAME) tests/randtestMAX.txt)

norme:
	norminette $(SOURCES) $(INCDIR)

clean:
	rm -rf build/

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

build:
	mkdir build/

.PHONY: clean fclean re
