# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 17:23:52 by dpaes-so          #+#    #+#              #
#    Updated: 2025/01/02 14:58:07 by dpaes-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = cc
FLAGS = -Wall -Werror -Wextra

SRC_FILES =	func_aux.c main.c stack_func.c calculationsB.c after_calcA.c operations.c operations_aux.c main_aux.c small_sort.c calculationsA.c
OBJS = $(SRC_FILES:.c=.o)
LIBFT = libft/libft.a

all: $(NAME) 

$(NAME): $(SRC_FILES) $(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $@

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./libft -s
clean:
	@rm -f $(OBJS)
	@make clean -C ./libft -s

fclean:clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re