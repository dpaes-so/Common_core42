/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:06:36 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/05 15:08:50 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animationgen(t_mlx *mlx)
{
	mlx->game.rigth.step1.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-1.xpm", &mlx->game.rigth.step1.w,
			&mlx->game.rigth.step1.t);
	mlx->game.rigth.step2.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-2.xpm", &mlx->game.rigth.step2.w,
			&mlx->game.rigth.step2.t);
	mlx->game.rigth.step3.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-3.xpm", &mlx->game.rigth.step3.w,
			&mlx->game.rigth.step3.t);
	mlx->game.rigth.step4.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-4.xpm", &mlx->game.rigth.step4.w,
			&mlx->game.rigth.step4.t);
	mlx->game.rigth.step5.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-5.xpm", &mlx->game.rigth.step5.w,
			&mlx->game.rigth.step5.t);
	mlx->game.rigth.step6.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-6.xpm", &mlx->game.rigth.step6.w,
			&mlx->game.rigth.step6.t);
	mlx->game.rigth.step7.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/step-7.xpm", &mlx->game.rigth.step7.w,
			&mlx->game.rigth.step7.t);
	left_side_anigen(mlx);
}

void	left_side_anigen(t_mlx *mlx)
{
	mlx->game.left.step1.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-1.xpm", &mlx->game.left.step1.w,
			&mlx->game.left.step1.t);
	mlx->game.left.step2.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-2.xpm", &mlx->game.left.step2.w,
			&mlx->game.left.step2.t);
	mlx->game.left.step3.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-3.xpm", &mlx->game.left.step3.w,
			&mlx->game.left.step3.t);
	mlx->game.left.step4.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-4.xpm", &mlx->game.left.step4.w,
			&mlx->game.left.step4.t);
	mlx->game.left.step5.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-5.xpm", &mlx->game.left.step5.w,
			&mlx->game.left.step5.t);
	mlx->game.left.step6.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-6.xpm", &mlx->game.left.step6.w,
			&mlx->game.left.step6.t);
	mlx->game.left.step7.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-7.xpm", &mlx->game.left.step7.w,
			&mlx->game.left.step7.t);
}

void	animationdestroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->game.rigth.step1.img);
	mlx_destroy_image(mlx->mlx, mlx->game.rigth.step2.img);
	mlx_destroy_image(mlx->mlx, mlx->game.rigth.step3.img);
	mlx_destroy_image(mlx->mlx, mlx->game.rigth.step4.img);
	mlx_destroy_image(mlx->mlx, mlx->game.rigth.step5.img);
	mlx_destroy_image(mlx->mlx, mlx->game.rigth.step6.img);
	mlx_destroy_image(mlx->mlx, mlx->game.rigth.step7.img);
	mlx_destroy_image(mlx->mlx, mlx->game.left.step1.img);
	mlx_destroy_image(mlx->mlx, mlx->game.left.step2.img);
	mlx_destroy_image(mlx->mlx, mlx->game.left.step3.img);
	mlx_destroy_image(mlx->mlx, mlx->game.left.step4.img);
	mlx_destroy_image(mlx->mlx, mlx->game.left.step5.img);
	mlx_destroy_image(mlx->mlx, mlx->game.left.step6.img);
	mlx_destroy_image(mlx->mlx, mlx->game.left.step7.img);
}
