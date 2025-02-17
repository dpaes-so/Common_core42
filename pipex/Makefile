# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 16:28:14 by dpaes-so          #+#    #+#              #
#    Updated: 2025/02/17 13:40:05 by dpaes-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus
CC = cc
FLAGS = -Wall -Werror -Wextra

SRC_FILES =	pipex.c aux.c
SRCB_FILES = pipex_bonus.c aux.c
OBJS = $(SRC_FILES:.c=.o)
BONUS_OBJS = $(SRCB_FILES:.c=.o)
LIBFT = includes/libft/libft.a

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT)
	@$(CC)  $(OBJS) $(LIBFT) -g -o $(NAME)

%.o: %.c
	@$(CC) -c -g $< -o $@
	
$(LIBFT):
	@$(MAKE) -C includes/libft -s
	
bonus:$(LIBFT) $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBFT) -g -o $(BONUS)

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@make clean -C includes/libft -s
fclean:clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@make fclean -C includes/libft -s

re: fclean all

.PHONY: all fclean clean re