/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:00 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/13 17:04:49 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

int	map_parse(char *map_file, t_map *map)
{
	int		fd;
	char	*str;

	map->row = 0;
	if (ft_strncmp(map_file + ft_strlen(map_file) - 4, ".ber", 4) != 0)
		return (0);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		str = get_next_line(fd);
		if (str)
			map->row++;
		else
			break ;
		free(str);
	}
	close(fd);
	if (map->row <= 0)
		return (0);
	map->map = make_maptrix(map->row, map_file);
	map->col = ft_strlen(map->map[1]);
	map_check(map);
	return (1);
}

void	play_right_animation(t_mlx *mlx)
{
	if (mlx->game.delay == 100)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.rigth.step1.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 200)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.rigth.step2.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 400)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.rigth.step3.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 600)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.rigth.step4.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 800)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.rigth.step5.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 1000)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.rigth.step6.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 1200)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.rigth.step7.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
		mlx->game.delay = 0;
	}
}

void	play_left_animation(t_mlx *mlx)
{
	if (mlx->game.delay == 100)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.left.step1.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 200)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.left.step2.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 400)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.left.step3.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 600)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.left.step4.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 800)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.left.step5.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 1000)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.left.step6.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
	if (mlx->game.delay == 1200)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.left.step7.img,
			(mlx->map.player.x) * 96 - 96, (mlx->map.player.y) * 96 - 96);
		mlx->game.delay = 0;
	}
}

int	anihook(t_mlx *mlx)
{
	static struct timeval	last_time;
	struct timeval			current_time;
	long					elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - last_time.tv_sec) * 1000
		+ (current_time.tv_usec - last_time.tv_usec) / 1000;
	if (elapsed_time >= 1)
	{
		if (mlx->game.flag == 1)
			play_right_animation(mlx);
		else
			play_left_animation(mlx);
		mlx->game.delay++;
		last_time = current_time;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2)
	{
		if (!map_parse(av[1], &mlx.map))
		{
			ft_printf("Error\nInvalid map file");
			exit(0);
		}
		mlx.game.delay = 0;
		mlx.mlx = mlx_init();
		map_gen(&mlx, &mlx.map);
		mlx_hook(mlx.win, 17, 0, closex, &mlx);
		mlx_key_hook(mlx.win, keys, &mlx);
		mlx_loop_hook(mlx.mlx, anihook, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_printf("Error\nPlease input 1 argument");
}
