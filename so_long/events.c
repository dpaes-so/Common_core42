/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:42:22 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/16 18:12:29 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouseprintf(int x, int y)
{
	ft_printf("Mouse moved to position: (%d, %d)\n", x, y);
	return (0);
}

int char_cmp(char c,char r)
{
	if (c - r == 0)
		return (1);
	else 
		return (0);
}
int	keys(int keycode, t_mlx *mlx)
{
	int x;
	int y;
	int f;
	static int moves;

	x = mlx->map.player.x;
	y = mlx->map.player.y;
	f = 0;
	ft_printf("total of moves: %d\n",moves);
	moves++;
	if (keycode == 65307)
	{
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
	if (keycode == 119)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
		if(char_cmp(mlx->map.map[y - 1][x],'1') == 0)
			f = -1;
		put_player(mlx,&mlx->map,0,f);
	}
	if (keycode == 115)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
		if(char_cmp(mlx->map.map[y + 1][x],'1') == 0)
			f = +1;
		put_player(mlx,&mlx->map,0,f);
	}
	if (keycode == 97)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
		if(char_cmp(mlx->map.map[y][x - 1],'1') == 0)
			f = -1;
		put_player(mlx,&mlx->map,f,0);
	}
	if (keycode == 100)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
		if(char_cmp(mlx->map.map[y][x + 1],'1') == 0)
			f = +1;
		put_player(mlx,&mlx->map,f,0);
	}
	return (0);
}
