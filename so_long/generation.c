/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:19:33 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/27 17:08:52 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_assets_gen(t_map *map, int *x, int *y)
{
	int	len;

	len = ft_strlen(map->map[0]) - 2;
	if (len > 20 || map->row > 7)
	{
		free_map(map);
		exit(0);
	}
	(*x) = (192 * len);
	(*y) = ((192 * (map->row - 2)));
}
void	window_generation(t_mlx *mlx, t_map *map)
{
	mlx->win = mlx_new_window(mlx->mlx, mlx->resx, mlx->resy, "so_long");
	mlx->bg.img = mlx_new_image(mlx->mlx, mlx->resx, mlx->resy);
	mlx->bg.addr = mlx_get_data_addr(mlx->bg.img, &mlx->bg.bits_per_pixel,
			&mlx->bg.line_length, &mlx->bg.endian);
}
void	put_player(t_mlx *mlx, t_map *map,int x,int y)
{
	static int coin_collected;

	if(!coin_collected)
		coin_collected = 0;
	mlx->map.player.x+= x;
	mlx->map.player.y += y;
	if(char_cmp(mlx->map.map[(mlx->map.player.y)][mlx->map.player.x],'c') == 1)
	{
		mlx->map.map[(mlx->map.player.y)][mlx->map.player.x] = 'g';
		coin_collected++;
		put_sprite(mlx);
	}
	if(char_cmp(mlx->map.map[(mlx->map.player.y)][mlx->map.player.x],'E') == 1 && coin_collected == mlx->map.coinn)
	{
		ft_printf("YOU WIN!!!!");
	close_game(mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win,mlx->game.play.img,(mlx->map.player.x - 1 )* 192,(mlx->map.player.y - 1)* 192);
}
void	map_gen(t_mlx *mlx, t_map *map)
{
	int	x;
	int	y;

	mlx->game.floor.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/4K/Grass.xpm", &mlx->game.floor.w, &mlx->game.floor.t);
	mlx->game.rock.img = mlx_xpm_file_to_image(mlx->mlx, "./assets/4K/Rock.xpm",
			&mlx->game.rock.w, &mlx->game.rock.t);
	mlx->game.coin.img = mlx_xpm_file_to_image(mlx->mlx, "./assets/4K/Coin.xpm",
			&mlx->game.coin.w, &mlx->game.coin.t);
	mlx->game.door.img = mlx_xpm_file_to_image(mlx->mlx, "./assets/4K/DOOR.xpm",
			&mlx->game.door.w, &mlx->game.door.t);
	mlx->game.play.img = mlx_xpm_file_to_image(mlx->mlx, "./assets/4K/Dora.xpm",
			&mlx->game.play.w, &mlx->game.play.t);
	map_assets_gen(map, &mlx->resx, &mlx->resy);
	window_generation(mlx, map);
	prep_sprite(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->bg.img, 0, 0);
	put_player(mlx,map,0,0);
}

void	prep_sprite(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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

// void	put_player(t_mlx *mlx, t_map *map)
// {
// 	char	*str;
// 	int		i;
// 	t_img	dora;
// 	int		x;
// 	int		y;
// 	int		j;

// 	y = 0;
// 	j = 0;
// 	dora.img = mlx_xpm_file_to_image(mlx->mlx, "./assets/4K/Dora.xpm",
// 			&dora.w, &dora.t);
// 	while (j < map->row - 2)
// 	{
// 		str = (map->map[++j]);
// 		x = 0;
// 		i = 1;
// 		while (str[i] && str[i] != '\n')
// 		{
// 			if (str[i] == 'p')
// 				mlx_put_image_to_window(mlx->mlx, mlx->win, dora.img, x, y);
// 			i++;
// 			x += 192;
// 		}
// 		y += 192;
// 	}
// }