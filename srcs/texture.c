#include "cub3d.h"
#include "stdio.h"

t_img	init_textures(t_vars *vars)
{
	t_img NO;
	//t_img SO;
	//t_img WE;
	//t_img EA;
//
	NO.relative_path = "assets/textures/wall1.xpm";
	//SO.relative_path = "assets/textures/wall2.xpm";
	//EA.relative_path = "assets/textures/wall3.xpm";
	//WE.relative_path = "assets/textures/wall4.xpm";

	NO.img = mlx_xpm_file_to_image(vars->mlx, NO.relative_path , &NO.img_width, &NO.img_height);


	//unsigned long tw = 64;
	//unsigned long th = 64;
//
	//draw->texture[0] = "assets/textures/bluestone.png";
	//draw->texture[1] = "assets/textures/redbrick.png";
	//draw->texture[2] = "assets/textures/wood.png";
	//draw->texture[0] = "assets/textures/mossy.png";
	return (NO);
}