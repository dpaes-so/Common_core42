/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:51:44 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/30 14:15:39 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_mlx *mlx)
{
	ft_printf("GAME CLOSING\n");
	animationdestroy(mlx);
	mlx_destroy_image(mlx->mlx, mlx->game.coin.img);
	mlx_destroy_image(mlx->mlx, mlx->game.door.img);
	mlx_destroy_image(mlx->mlx, mlx->game.play.img);
	mlx_destroy_image(mlx->mlx, mlx->game.rock.img);
	mlx_destroy_image(mlx->mlx, mlx->game.floor.img);
	mlx_destroy_image(mlx->mlx, mlx->bg.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free_map(&mlx->map);
	free(mlx->mlx);
	exit(0);
}

int	char_cmp(char c, char r)
{
	if (c - r == 0)
		return (1);
	else
		return (0);
}
