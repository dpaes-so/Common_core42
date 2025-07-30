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

NAME = Philo
CC = cc
FLAGS = -Wall -Werror -Wextra -pthread -g

SRC_FILES = jean_paul.c time.c parser.c to_lib_or_not_to_lib.c
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) -c -g $< -o $@

clean:
	@rm -f $(OBJS)

fclean:clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus