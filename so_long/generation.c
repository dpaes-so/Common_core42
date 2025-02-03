/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:19:33 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/30 16:19:21 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_assets_gen(t_map *map, int *x, int *y)
{
	int	len;

	len = ft_strlen(map->map[0]) - 2;
	if (len > 20 || map->row > 12)
	{
		ft_printf("map to big\n");
		free_map(map);
		exit(0);
	}
	(*x) = (96 * len);
	(*y) = ((96 * (map->row - 2)));
}

void	window_generation(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->mlx, mlx->resx, mlx->resy, "so_long");
	mlx->bg.img = mlx_new_image(mlx->mlx, mlx->resx, mlx->resy);
	mlx->bg.addr = mlx_get_data_addr(mlx->bg.img, &mlx->bg.bits_per_pixel,
			&mlx->bg.line_length, &mlx->bg.endian);
}

void	put_player(t_mlx *mlx, t_map *map, int x, int y)
{
	mlx->map.player.x += x;
	mlx->map.player.y += y;
	if (char_cmp(map->map[(map->player.y)][map->player.x], 'c') == 1)
	{
		map->map[(map->player.y)][map->player.x] = '0';
		map->coin_collected++;
		put_sprite(mlx);
	}
	if (char_cmp(map->map[(map->player.y)][map->player.x], 'E') == 1
		&& map->coin_collected == map->coinn)
	{
		ft_printf("WOW %d GOLD COINS!? WE CAN MARRY NOW\n",
			map->coin_collected);
		close_game(mlx);
	}
	else if (char_cmp(map->map[(map->player.y)][map->player.x], 'E') == 1
		&& !(map->coin_collected == map->coinn))
	{
		ft_printf("ONLY RICH MEN CAN MARRY ME\n");
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.play.img,
		(mlx->map.player.x - 1) * 96, (mlx->map.player.y - 1) * 96);
}

void	map_gen(t_mlx *mlx, t_map *map)
{
	mlx->game.step1.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-1.xpm", &mlx->game.step1.w, &mlx->game.step1.t);
	mlx->game.step2.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-2.xpm", &mlx->game.step2.w, &mlx->game.step2.t);
	mlx->game.step3.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-3.xpm", &mlx->game.step3.w, &mlx->game.step3.t);
	mlx->game.step4.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-4.xpm", &mlx->game.step4.w, &mlx->game.step4.t);
	mlx->game.step5.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-5.xpm", &mlx->game.step5.w, &mlx->game.step5.t);
	mlx->game.step6.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-6.xpm", &mlx->game.step6.w, &mlx->game.step6.t);
	mlx->game.step7.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-7.xpm", &mlx->game.step7.w, &mlx->game.step7.t);
	mlx->game.floor.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/4K/Grass.xpm", &mlx->game.floor.w, &mlx->game.floor.t);
	mlx->game.rock.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/4K/good_rock.xpm", &mlx->game.rock.w, &mlx->game.rock.t);
	mlx->game.coin.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/4K/good_coin.xpm", &mlx->game.coin.w, &mlx->game.coin.t);
	mlx->game.door.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/4K/prince.xpm", &mlx->game.door.w, &mlx->game.door.t);
	mlx->game.play.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-1.xpm", &mlx->game.play.w, &mlx->game.play.t);
	map_assets_gen(map, &mlx->resx, &mlx->resy);
	window_generation(mlx);
	mlx->game.moves = 0;
	mlx->map.coin_collected = 0;
	mlx->flag = 0;
	prep_sprite(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->game.play.img,
		(mlx->map.player.x - 1) * 96, (mlx->map.player.y - 1) * 96);
}

void	prep_sprite(t_mlx *mlx)
{
	mlx->game.floor.addr = mlx_get_data_addr(mlx->game.floor.img,
			&mlx->game.floor.bits_per_pixel, &mlx->game.floor.line_length,
			&mlx->game.floor.endian);
	mlx->game.door.addr = mlx_get_data_addr(mlx->game.door.img,
			&mlx->game.door.bits_per_pixel, &mlx->game.door.line_length,
			&mlx->game.door.endian);
	mlx->game.rock.addr = mlx_get_data_addr(mlx->game.rock.img,
			&mlx->game.rock.bits_per_pixel, &mlx->game.rock.line_length,
			&mlx->game.rock.endian);
	mlx->game.coin.addr = mlx_get_data_addr(mlx->game.coin.img,
			&mlx->game.coin.bits_per_pixel, &mlx->game.coin.line_length,
			&mlx->game.coin.endian);
	mlx->game.play.addr = mlx_get_data_addr(mlx->game.play.img,
			&mlx->game.play.bits_per_pixel, &mlx->game.play.line_length,
			&mlx->game.play.endian);
	put_sprite(mlx);
}
