/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:29:32 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/06 14:10:09 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
		free(map->map[i++]);
	free(map->map);
}

void	wallerror(t_map *map)
{
	ft_printf("Error\nThe map its not closed\n");
	free_map(map);
	exit(0);
}

int	pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	closex(t_mlx *mlx)
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
	return (0);
}
