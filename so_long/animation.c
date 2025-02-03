#include "so_long.h"

void animationgen(t_mlx *mlx)
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

    //mirror
    mlx->game.mirror1.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-1.xpm", &mlx->game.mirror1.w, &mlx->game.mirror1.t);
	mlx->game.mirror2.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-2.xpm", &mlx->game.mirror2.w, &mlx->game.mirror2.t);
	mlx->game.mirror3.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-3.xpm", &mlx->game.mirror3.w, &mlx->game.mirror3.t);
	mlx->game.mirror4.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-4.xpm", &mlx->game.mirror4.w, &mlx->game.mirror4.t);
	mlx->game.mirror5.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-5.xpm", &mlx->game.mirror5.w, &mlx->game.mirror5.t);
	mlx->game.mirror6.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-6.xpm", &mlx->game.mirror6.w, &mlx->game.mirror6.t);
	mlx->game.mirror7.img = mlx_xpm_file_to_image(mlx->mlx,
			"./assets/mirror-7.xpm", &mlx->game.mirror7.w, &mlx->game.mirror7.t);
    
}


void animationdestroy(t_mlx *mlx)
{
    mlx_destroy_image(mlx->mlx, mlx->game.step1.img);
	mlx_destroy_image(mlx->mlx, mlx->game.step2.img);
	mlx_destroy_image(mlx->mlx, mlx->game.step3.img);
	mlx_destroy_image(mlx->mlx, mlx->game.step4.img);
	mlx_destroy_image(mlx->mlx, mlx->game.step5.img);
	mlx_destroy_image(mlx->mlx, mlx->game.step6.img);
	mlx_destroy_image(mlx->mlx, mlx->game.step7.img);
    //mirror
    mlx_destroy_image(mlx->mlx, mlx->game.mirror1.img);
	mlx_destroy_image(mlx->mlx, mlx->game.mirror2.img);
	mlx_destroy_image(mlx->mlx, mlx->game.mirror3.img);
	mlx_destroy_image(mlx->mlx, mlx->game.mirror4.img);
	mlx_destroy_image(mlx->mlx, mlx->game.mirror5.img);
	mlx_destroy_image(mlx->mlx, mlx->game.mirror6.img);
	mlx_destroy_image(mlx->mlx, mlx->game.mirror7.img);
}
