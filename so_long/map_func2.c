/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:27:57 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/06 14:20:16 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_maptrix(int row, char *map_file)
{
	char	**maptrix;
	int		i;
	int		fd;

	i = 0;
	fd = open(map_file, O_RDONLY);
	maptrix = malloc(sizeof(char *) * row + 1);
	if (!maptrix)
		return (NULL);
	while (i < row)
	{
		maptrix[i] = get_next_line(fd);
		i++;
	}
	i = 0;
	return (maptrix);
}

void	map_type(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map->map[0]);
	while (i < map->row)
	{
		if (((ft_strlen(map->map[i]) != len) || (map->row < 3)))
		{
			ft_printf("Error\nMap is not a rectangle or too short");
			free_map(map);
			exit(0);
		}
		i++;
	}
}

void	map_wall(t_map *map, int len, int row)
{
	int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1' && map->map[0][i] != '\n')
			wallerror(map);
		i++;
	}
	i = 1;
	while (i < row)
	{
		if (map->map[i][0] != '1')
			wallerror(map);
		if (map->map[i][len - 1] != '1')
			wallerror(map);
		i++;
	}
	i = 0;
	while (map->map[row][i])
	{
		if (map->map[row][i] != '1' && map->map[row][i] != '\n')
			wallerror(map);
		i++;
	}
}

void	flood_fill(t_map *map, int x, int y)
{
	if (map->map[y][x] != 'P' && map->map[y][x] != 'C' && map->map[y][x] != '0'
		&& map->map[y][x] != 'E')
		return ;
	if (map->map[y][x] == 'P')
		map->map[y][x] = 'p';
	else if (map->map[y][x] == 'C')
		map->map[y][x] = 'c';
	else if (map->map[y][x] == '0')
		map->map[y][x] = 'o';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}

void	check_2_many(t_map *map)
{
	if (map->player_n != 1)
	{
		ft_printf("Error\nThe map needs one player");
		free_map(map);
		exit(0);
	}
	if (map->coinn < 1)
	{
		ft_printf("Error\nPlease add at least 1 collectible");
		free_map(map);
		exit(0);
	}
	if (map->exitn != 1)
	{
		ft_printf("Error\nThe map needs to have exactly 1 exit\n");
		free_map(map);
		exit(0);
	}
	if (map->extra > 0)
	{
		ft_printf("Error\nnot know character in the map");
		free_map(map);
		exit(0);
	}
}
