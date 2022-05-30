# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayar <sayar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 11:35:24 by sayar             #+#    #+#              #
#    Updated: 2022/03/10 14:55:13 by sayar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

FLAGS = -Wall -Wextra -Werror

CC = cc

SRC_M = push_swap.c ft_build_stack.c operation_stack.c operations_stack.c ft_sort_short.c ft_print_insta.c ft_new_stack.c ft_min_sort.c ft_algo.c ft_algo_a.c ft_algo_b.c error_check.c

SRC_B = ./bonus/checker_bonus.c ft_build_stack.c operation_stack.c operations_stack.c ft_sort_short.c ft_print_insta.c ft_new_stack.c ft_min_sort.c ft_algo.c ft_algo_a.c ft_algo_b.c error_check.c ./bonus/ft_check_stack_bonus.c ./bonus/ft_comp_moves_bonus.c ./bonus/get_next_line_utils_bonus.c ./bonus/get_next_line_bonus.c

OBJ_M = ${patsubst %.c, %.o, ${SRC_M}}

OBJ_B = ${patsubst %.c, %.o, ${SRC_B}}

all : ${NAME}

.PHONY : all clean fclean re

libft/libft.a:
	make -C libft

${NAME} : libft/libft.a ${OBJ_M} push_swap.h
	${CC} ${FLAGS} ${OBJ_M} libft/libft.a -o ${NAME}

${NAME_B} : libft/libft.a ${OBJ_B} ./bonus/checker_bonus.h
	${CC} ${FLAGS} ${OBJ_B} libft/libft.a -o ${NAME_B}

bonus : ${NAME} ${NAME_B}

clean :
	rm -rf ${OBJ_M}
	rm -rf ${OBJ_B}
	make -C libft clean

fclean : clean
	rm -rf ${NAME}
	rm -rf ${NAME_B}
	make -C libft fclean

re : fclean all