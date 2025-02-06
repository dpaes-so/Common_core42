/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:00:07 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/06 14:10:45 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_count(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				map->player_n++;
			else if (map->map[i][j] == 'C')
				map->coinn++;
			else if (map->map[i][j] == 'E')
				map->exitn++;
			else if (map->map[i][j] == '0')
				map->wall++;
			else if (map->map[i][j] == '1')
				map->path++;
			else if (map->map[i][j] != '\n')
				map->extra++;
		}
	}
	check_2_many(map);
}

int	check_if_coin(t_map *map)
{
	int	i;
	int	j;
	int	coin_collected;

	coin_collected = 0;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (map->map[i][++j])
			if (map->map[i][j] == 'c')
				coin_collected++;
	}
	if (coin_collected == map->coinn)
		return (1);
	else
		return (0);
}

int	check_if_possible(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'E')
			{
				x = j;
				y = i;
			}
		}
	}
	if (map->map[y + 1][x] == 'o' || map->map[y - 1][x] == 'o' || map->map[y
		+ 1][x] == 'c' || map->map[y - 1][x] == 'c')
		return (check_if_coin(map));
	else if (map->map[y][x + 1] == 'o' || map->map[y][x - 1] == 'o'
		|| map->map[y][x + 1] == 'c' || map->map[y][x - 1] == 'c')
		return (check_if_coin(map));
	return (0);
}

int	check_path(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	f;

	f = 1;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player.x = j;
				map->player.y = i;
			}
		}
	}
	x = map->player.x;
	y = map->player.y;
	flood_fill(map, x, y);
	f = check_if_possible(map);
	return (f);
}

void	map_check(t_map *map)
{
	int	len;
	int	row;
	int	f;

	map->player_n = 0;
	map->coinn = 0;
	map->exitn = 0;
	map->wall = 0;
	map->path = 0;
	map->extra = 0;
	row = map->row - 1;
	len = ft_strlen(map->map[0]);
	map_type(map);
	map_count(map);
	map_wall(map, len, row);
	f = check_path(map);
	if (!f)
	{
		ft_printf("Error\nthe map is not possible");
		free_map(map);
		exit(0);
	}
}
