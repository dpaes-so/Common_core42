# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 16:28:14 by dpaes-so          #+#    #+#              #
#    Updated: 2025/04/03 14:25:45 by dpaes-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC_FILES =	pipex.c aux.c arg_split.c
SRCB_FILES = pipex_bonus.c aux_bonus.c arg_split.c more_aux_bonus.c
OBJS = $(SRC_FILES:.c=.o)
BONUS_OBJS = $(SRCB_FILES:.c=.o)
LIBFT = includes/libft/libft.a

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -g -o $(NAME)

%.o: %.c
	@$(CC) -c -g $< -o $@
	
$(LIBFT):
	@$(MAKE) -C includes/libft -s
	
bonus:$(LIBFT) $(BONUS_OBJS)
	@$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -g -o $(BONUS)

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@make clean -C includes/libft -s
fclean:clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@make fclean -C includes/libft -s

re: fclean all

.PHONY: all fclean clean re bonus