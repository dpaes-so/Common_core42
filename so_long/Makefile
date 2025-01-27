# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:34:53 by dpaes-so          #+#    #+#              #
#    Updated: 2025/01/16 17:21:05 by dpaes-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = cc
FLAGS = -Wall -Werror -Wextra

SRC_FILES =	main.c aux.c map_func.c map_func2.c events.c generation.c sprite_gen.c
OBJS = $(SRC_FILES:.c=.o)
LIBFT = includes/libft/libft.a

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@
	
$(LIBFT):
	@$(MAKE) -C includes/libft
clean:
	@rm -f $(OBJS)
fclean:clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re