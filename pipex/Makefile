# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaes-so <dpaes-so@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 16:28:14 by dpaes-so          #+#    #+#              #
#    Updated: 2025/02/10 16:29:32 by dpaes-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
FLAGS = -Wall -Werror -Wextra

SRC_FILES =	pipex.c
OBJS = $(SRC_FILES:.c=.o)
LIBFT = includes/libft/libft.a

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
$(LIBFT):
	@$(MAKE) -C includes/libft
clean:
	@rm -f $(OBJS)
	@make clean -C includes/libft
fclean:clean
	@rm -f $(NAME)
	@make fclean -C includes/libft

re: fclean all

.PHONY: all fclean clean re