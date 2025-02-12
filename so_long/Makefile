# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:34:53 by dpaes-so          #+#    #+#              #
#    Updated: 2025/02/12 15:36:23 by dpaes-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = cc
FLAGS = -Wall -Werror -Wextra
MLX = mlx_linux/libmlx.a

SRC_FILES =	main.c aux.c map_func.c map_func2.c events.c generation.c sprite_gen.c more_aux.c animation.c
OBJS = $(SRC_FILES:.c=.o)
LIBFT = includes/libft/libft.a

all: $(NAME) 

$(NAME):$(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -g -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	
$(LIBFT):
	@$(MAKE) -C includes/libft
	
$(MLX):
	@make -C mlx_linux
clean:
	@rm -f $(OBJS)
	@make clean -C includes/libft
fclean:clean
	@rm -f $(NAME)
	@make fclean -C includes/libft

re: fclean all

.PHONY: all fclean clean re