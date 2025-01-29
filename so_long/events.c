/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:42:22 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/29 17:58:07 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouseprintf(int x, int y)
{
	ft_printf("Mouse moved to position: (%d, %d)\n", x, y);
	return (0);
}

int	char_cmp(char c, char r)
{
	if (c - r == 0)
		return (1);
	else
		return (0);
}

void	move_up(int f, t_mlx *mlx, int x, int y)
{
	if (char_cmp(mlx->map.map[y - 1][x], '1') == 0)
		f = -1;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	put_player(mlx, &mlx->map, 0, f);
}

void	move_down(int f, t_mlx *mlx, int x, int y)
{
	if (char_cmp(mlx->map.map[y + 1][x], '1') == 0)
		f = +1;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	put_player(mlx, &mlx->map, 0, f);
}
void	move_right(int f, t_mlx *mlx, int x, int y)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	if (char_cmp(mlx->map.map[y][x + 1], '1') == 0)
		f = +1;
	mlx_destroy_image(mlx->mlx, mlx->game.play.img);
	mlx->game.play.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/4K/good_cav.xpm", &mlx->game.play.w, &mlx->game.play.t);
	put_player(mlx, &mlx->map, f, 0);
}

void	move_left(int f, t_mlx *mlx, int x, int y)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	if (char_cmp(mlx->map.map[y][x - 1], '1') == 0)
		f = -1;
	mlx_destroy_image(mlx->mlx, mlx->game.play.img);
	mlx->game.play.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/4K/good_mirror.xpm", &mlx->game.play.w,
			&mlx->game.play.t);
	put_player(mlx, &mlx->map, f, 0);
}
int	keys(int keycode, t_mlx *mlx)
{
	int			x;
	int			y;
	int			f;
	static int	moves;

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
	if (f != 0)
		ft_printf("total of moves: %d\n", moves++);
	return (0);
}
