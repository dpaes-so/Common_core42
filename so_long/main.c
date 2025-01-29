/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:00 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/29 16:27:37 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map->map = make_maptrix(map->row, map_file);
	map->col = ft_strlen(map->map[1]);
	map_check(map);
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac == 2)
	{
		if (!map_parse(av[1], &mlx.map))
		{
			ft_printf("invalid map file");
			exit(0);
		}
		mlx.mlx = mlx_init();
		map_gen(&mlx, &mlx.map);
		mlx_hook(mlx.win,17,0,closeX,&mlx);
		// mlx_hook(mlx.win,02,1L<<0,keys,&mlx);
		mlx_key_hook(mlx.win, keys, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_printf("please input 1 argument");
}
