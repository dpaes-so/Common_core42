/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:15:42 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/29 17:58:44 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_mlx *mlx, int cx, int cy)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < 96)
	{
		x = 0;
		while (x < 96)
		{
			my_mlx_pixel_put(&mlx->bg, cx * 96 + x - 96, cy * 96 + y - 96,
				pixel_get(&mlx->game.floor, x, y));
			x++;
		}
		y++;
	}
}

void	put_rock(t_mlx *mlx, int cx, int cy)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < 96)
	{
		x = 0;
		while (x < 96)
		{
			my_mlx_pixel_put(&mlx->bg, cx * 96 + x - 96, cy * 96 + y - 96,
				pixel_get(&mlx->game.rock, x, y));
			x++;
		}
		y++;
	}
}

void	put_coin(t_mlx *mlx, int cx, int cy)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < 96)
	{
		x = 0;
		while (x < 96)
		{
			my_mlx_pixel_put(&mlx->bg, cx * 96 + x - 96, cy * 96 + y - 96,
				pixel_get(&mlx->game.coin, x, y));
			x++;
		}
		y++;
	}
}

void	put_door(t_mlx *mlx, int cx, int cy)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < 96)
	{
		x = 0;
		while (x < 96)
		{
			my_mlx_pixel_put(&mlx->bg, cx * 96 + x - 96, cy * 96 + y - 96,
				pixel_get(&mlx->game.door, x, y));
			x++;
		}
		y++;
	}
}

void	put_sprite(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 1;
	while (y < mlx->map.row - 1)
	{
		x = 1;
		while (x < mlx->map.col - 1)
		{
			if (mlx->map.map[y][x] == 'o' || mlx->map.map[y][x] == '0'
				|| mlx->map.map[y][x] == 'p')
				put_floor(mlx, x, y);
			else if (mlx->map.map[y][x] == '1')
				put_rock(mlx, x, y);
			else if (mlx->map.map[y][x] == 'c')
				put_coin(mlx, x, y);
			else if (mlx->map.map[y][x] == 'E')
				put_door(mlx, x, y);
			x++;
		}
		y++;
	}
}
