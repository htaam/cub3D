#include "cub3d.h"
#include "stdio.h"

t_img	init_textures(t_vars *vars)
{
	t_img NO;

	NO.relative_path = "assets/textures/wall1.xpm";
	NO.img = mlx_xpm_file_to_image(vars->mlx, NO.relative_path , &NO.img_width, &NO.img_height);
	return (NO);
}