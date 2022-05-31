/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:56:25 by marmota           #+#    #+#             */
/*   Updated: 2022/05/31 20:57:34 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"
#define ScreenWith 1080
#define ScreenHeight 1080

void	init_stuff(t_vars *vars)
{
	int x_max = ScreenHeight;
	int y_max = ScreenWith;
	
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x_max,
			y_max, "A");
	vars->image.img = mlx_new_image(vars->mlx, x_max,
			y_max);
	vars->image.addr = mlx_get_data_addr(vars->image.img,
			&vars->image.bits_per_pixel,
			&vars->image.line_length, &vars->image.endian);
}

int max_height(double wall_distance)
{
    int lineHeight;
    int drawStart;

    lineHeight = (int)(ScreenHeight / wall_distance);
    drawStart = -lineHeight / 2 + ScreenHeight / 2;
    if (drawStart < 0)
        return (0);
    return(drawStart); 
}

int min_height(double wall_distance)
{

    int lineHeight;
    int drawEnd;

    lineHeight = (int)(ScreenHeight / wall_distance);
    drawEnd = lineHeight / 2 + ScreenHeight / 2;
    if (drawEnd >= ScreenHeight)
        return ( ScreenHeight - 1);
    return(drawEnd); 
}


void	draw_stuff(t_vars vars)
{
	double screen_x = 0;
	t_data image;

	mlx_clear_window(vars.mlx, vars.win);
	image.img = mlx_new_image(vars.mlx, ScreenWith,
			ScreenHeight);
	image.addr = mlx_get_data_addr(image.img,
			&image.bits_per_pixel,
			&image.line_length, &image.endian);

	while (++screen_x < ScreenWith)
	{
		double	camera_x = 2 * (screen_x / ScreenWith) - 1;
		double	ray_dir_x = vars.player.dir_x + (vars.player.plane_x * camera_x);
		double	ray_dir_y = vars.player.dir_y + (vars.player.plane_y * camera_x);

		int mapx = (int)(vars.player.pos_x);
		int mapy = (int)(vars.player.pos_y);

		double sideDistx;
		double sideDisty;
		double deltaDistx;
		double deltaDisty;

		if (ray_dir_x == 0)
			deltaDistx = 1e10;
		else
			deltaDistx = fabs(1 / ray_dir_x);

		if (ray_dir_y == 0)
			deltaDisty = 1e10;
		else
			deltaDisty = fabs(1 / ray_dir_y);

		int stepx;
		int stepy;

		int hit = 0;
		int side;

		if(ray_dir_x < 0)
		{
			stepx = -1;
			sideDistx = (vars.player.pos_x - mapx) * deltaDistx;
		}
		else
		{
			stepx = 1;
			sideDistx = (mapx + 1 - vars.player.pos_x) * deltaDistx;
		}
		if (ray_dir_y < 0)
		{
			stepy = -1;
			sideDisty = (vars.player.pos_y - mapy) * deltaDisty;
		}
		else
		{
			stepy = 1;
			sideDisty = (mapy + 1 - vars.player.pos_y) * deltaDisty;
		}
		while (hit == 0)
		{
			if (sideDistx < sideDisty)
			{
				sideDistx += deltaDistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sideDisty += deltaDisty;
				mapy += stepy;
				side = 1;
			}
			if (vars.game->board[mapx][mapy] != '0')
				hit = 1;
		}
		double perpWallDist;
		

		if (side == 0)
			perpWallDist = (sideDistx - deltaDistx);
		else
			perpWallDist = (sideDisty - deltaDisty);
		
		int screen_y = 0;
		while (++screen_y < ScreenHeight)
		{
			if (screen_y <= (min_height(perpWallDist)) && screen_y >= max_height(perpWallDist))
			{
				my_mlx_pixel_put(&image, screen_x,
					screen_y, (create_trgb(100*side, (int)vars.game->board[mapx][mapy] * 50,
							100, 0)));
			}
			else if ( screen_y  > (min_height(perpWallDist)))
			{
				my_mlx_pixel_put(&image, screen_x,
					screen_y, (create_trgb(0, vars.game->rgb.cr,
							vars.game->rgb.cg, vars.game->rgb.cb)));
			}
			else
			{
				my_mlx_pixel_put(&image, screen_x,
					screen_y, (create_trgb(0, vars.game->rgb.fr,
							vars.game->rgb.fg, vars.game->rgb.fb)));
			}
		}
		
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_destroy_image(vars.mlx, image.img);
}

void	init_vars(t_game *game)
{
	game->rgb.cr = -1;
	game->rgb.cg = -1;
	game->rgb.cb = -1;
	game->rgb.fr = -1;
	game->rgb.fg = -1;
	game->rgb.fb = -1;
	game->board = 0;
	game->board_height = 0;
}
