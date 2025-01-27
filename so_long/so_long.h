/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:34:54 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/27 16:55:19 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "includes/libft/libft.h"
# include "mlx_linux/mlx.h"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			w;
	int			t;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_assets
{
	t_img		coin;
	t_img		door;
	t_img		play;
	t_img		rock;
	t_img		floor;
}				t_assets;

typedef struct s_map
{
	char		**map;
	int			player_n;
	int			coinn;
	int			exitn;
	int			row;
	int			col;
	int			wall;
	int			path;
	int			extra;
	t_point		player;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			resx;
	int			resy;
	t_img		bg;
	t_map		map;
	t_assets	game;
}				t_mlx;

void			map_check(t_map *map);
void			map_type(t_map *map);
char			**make_maptrix(int row, char *map_file);
void			wallerror(t_map *map);
int				check_path(t_map *map);
void			flood_fill(t_map *map, int x, int y);
void			check_2_many(t_map *map);
int				mouseprintf(int x, int y);
int				keys(int keycode, t_mlx *mlx);

// events
int				char_cmp(char c, char r);
// aux
int				pixel_get(t_img *data, int x, int y);
void			free_map(t_map *map);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			map_wall(t_map *map, int len, int row);
int				closeX(t_mlx *mlx);
// more aux
void			close_game(t_mlx *mlx);
void			player_move(t_mlx *mlx);
// sprit gen
void			put_door(t_mlx *mlx, int cx, int cy);
void			put_coin(t_mlx *mlx, int cx, int cy);
void			put_rock(t_mlx *mlx, int cx, int cy);
void			put_floor(t_mlx *mlx, int cx, int cy);
void			put_sprite(t_mlx *mlx);
// generations
void			window_generation(t_mlx *mlx, t_map *map);
void			map_assets_gen(t_map *map, int *x, int *y);
void			map_gen(t_mlx *mlx, t_map *map);
void			put_player(t_mlx *mlx, t_map *map, int x, int y);
void	prep_sprite(t_mlx *mlx); // not really but no space
#endif