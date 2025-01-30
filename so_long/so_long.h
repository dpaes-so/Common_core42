/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:34:54 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/30 14:49:33 by dpaes-so         ###   ########.fr       */
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

typedef struct s_game
{
	t_img		coin;
	t_img		door;
	t_img		play;
	t_img		rock;
	t_img		floor;
	int			moves;
	int			delay;
}				t_game;

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
	int			coin_collected;
	t_point		player;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			resx;
	int			resy;
	int			exit_allowed;
	t_point		pixel;
	t_img		bg;
	t_map		map;
	t_game		game;
}				t_mlx;
// animations tryout
typedef struct s_animation
{
	t_list		*frames;
	int			width;
	int			height;
	int			delay;
	int			_tmp_delay;
	int			current_frame_num;
	long int	last_updated;
	long int	frame_count;
}				t_animation;

typedef struct s_sprite
{
	t_list		*animations;
	char		*name;
	char		*file_path;
	t_img		sprite_img;
	int			width;
	int			height;
	int			z_index;
}				t_sprite;

typedef struct s_slice
{
	int			x;
	int			y;
	int			width;
	int			height;
}				t_slice;

// events
int				keys(int keycode, t_mlx *mlx);
void			move_up(int f, t_mlx *mlx, int x, int y);
void			move_down(int f, t_mlx *mlx, int x, int y);
void			move_right(int f, t_mlx *mlx, int x, int y);
void			move_left(int f, t_mlx *mlx, int x, int y);
// aux
int				pixel_get(t_img *data, int x, int y);
void			free_map(t_map *map);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
int				closex(t_mlx *mlx);
void			wallerror(t_map *map);
// more aux
int				char_cmp(char c, char r);
void			close_game(t_mlx *mlx);
// map func
void			map_check(t_map *map);
int				check_path(t_map *map);
int				check_if_possible(t_map *map);
int				check_if_coin(t_map *map);
void			map_count(t_map *map);
// map func 2
char			**make_maptrix(int row, char *map_file);
void			map_type(t_map *map);
void			map_wall(t_map *map, int len, int row);
void			flood_fill(t_map *map, int x, int y);
void			check_2_many(t_map *map);
// sprite gen
void			put_door(t_mlx *mlx, int cx, int cy);
void			put_coin(t_mlx *mlx, int cx, int cy);
void			put_rock(t_mlx *mlx, int cx, int cy);
void			put_floor(t_mlx *mlx, int cx, int cy);
void			put_sprite(t_mlx *mlx);
// generations
void			window_generation(t_mlx *mlx);
void			map_assets_gen(t_map *map, int *x, int *y);
void			map_gen(t_mlx *mlx, t_map *map);
void			put_player(t_mlx *mlx, t_map *map, int x, int y);
void	prep_sprite(t_mlx *mlx); // not really but no space

// animations tryout
t_img			new_image(char *path, t_mlx *mlx);
#endif