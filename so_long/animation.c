/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:59:33 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/29 12:37:27 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void new_image(t_mlx *mlx)
{
	t_img img;
	int x;
	int y;

	
	img.img = mlx_xpm_file_to_image(mlx->mlx, "./assets/4K/ani/Run.xpm",&x, &y);
	mlx_put_image_to_window(mlx->mlx,mlx->win,img.img,0,0);
}