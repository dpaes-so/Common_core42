/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:42:22 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/12 16:42:50 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(int f, t_mlx *mlx, int x, int y)
{
	if (char_cmp(mlx->map.map[y - 1][x], '1') == 0)
	{
		f = -1;
		ft_printf("total of moves: %d\n", mlx->game.moves++);
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	put_player(mlx, &mlx->map, 0, f);
}

void	move_down(int f, t_mlx *mlx, int x, int y)
{
	if (char_cmp(mlx->map.map[y + 1][x], '1') == 0)
	{
		f = +1;
		ft_printf("total of moves: %d\n", mlx->game.moves++);
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	put_player(mlx, &mlx->map, 0, f);
}

void	move_right(int f, t_mlx *mlx, int x, int y)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	if (char_cmp(mlx->map.map[y][x + 1], '1') == 0)
	{
		f = +1;
		ft_printf("total of moves: %d\n", mlx->game.moves++);
	}
	if(mlx->game.flag != 1)
	{
		mlx_destroy_image(mlx->mlx, mlx->game.play.img);
		mlx->game.play.img = mlx_xpm_file_to_image(mlx->mlx, "./assets/step-1.xpm",
				&mlx->game.play.w, &mlx->game.play.t);
		mlx->game.flag = 1;
	}
	put_player(mlx, &mlx->map, f, 0);
}

void	move_left(int f, t_mlx *mlx, int x, int y)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	if (char_cmp(mlx->map.map[y][x - 1], '1') == 0)
	{
		f = -1;
		ft_printf("total of moves: %d\n", mlx->game.moves++);
	}
	if(mlx->game.flag != 0)
	{
		mlx_destroy_image(mlx->mlx, mlx->game.play.img);
		mlx->game.play.img = mlx_xpm_file_to_image(mlx->mlx,
				"./assets/mirror-1.xpm", &mlx->game.play.w, &mlx->game.play.t);
		mlx->game.flag = 0;
	}
	put_player(mlx, &mlx->map, f, 0);
}

int	keys(int keycode, t_mlx *mlx)
{
	int	x;
	int	y;
	int	f;

	x = mlx->map.player.x;
	y = mlx->map.player.y;
	f = 0;
	if (keycode == 65307)
		close_game(mlx);
	if (keycode == 119)
		move_up(f, mlx, x, y);
	else if (keycode == 115)
		move_down(f, mlx, x, y);
	else if (keycode == 97)
		move_left(f, mlx, x, y);
	else if (keycode == 100)
		move_right(f, mlx, x, y);
	if (mlx->map.coin_collected == mlx->map.coinn)
		mlx->exit_allowed = 1;
	return (0);
}
