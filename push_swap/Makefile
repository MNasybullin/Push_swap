# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 13:24:05 by aannara           #+#    #+#              #
#    Updated: 2020/09/02 09:15:39 by sdiego           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

SRC = ./src/get_next_line.c ./src/mem_lst.c ./src/print_err.c ./src/mini_lib.c ./src/mini_lib2.c\
	./src/stack.c ./src/rules.c ./src/mini_lib3.c ./src/debug.c ./src/get_argv.c ./src/rules_check.c\
	./src/markup.c ./src/index.c ./src/solve_gt.c ./src/solve_index.c ./src/direction.c ./src/solve_b.c\
	./src/ft_strsplit.c

SRC_CHECKER = ./src/checker.c

SRC_PUSH_SWAP = ./src/push_swap.c

OBJ = $(SRC:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

CFLAGS = -o

INCLUDES = ./include

HEADERS = $(INCLUDES)/push_swap.h $(INCLUDES)/get_next_line.h $(INCLUDES)/mem_lst.h

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ) $(OBJ_CHECKER) $(HEADERS)
	gcc $(CFLAGS) $(NAME1) $(OBJ) $(OBJ_CHECKER) -I$(INCLUDES)

$(NAME2): $(OBJ) $(OBJ_PUSH_SWAP) $(HEADERS)
	gcc $(CFLAGS) $(NAME2) $(OBJ) $(OBJ_PUSH_SWAP) -I$(INCLUDES)

.c.o: $(HEADERS)
	gcc -I$(INCLUDES) -c $< -o $@

clean:
	rm -fr ./src/*.o

fclean: clean
	rm -fr $(NAME1)
	rm -fr $(NAME2)

re: fclean all
