/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:57:21 by mmota             #+#    #+#             */
/*   Updated: 2022/06/10 22:50:09 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_aux1(t_draw *draw, t_vars vars)
{
	if (draw->side == 0 || draw->side == 2)
			draw->perpwalldist = (draw->sidedistx - draw->deltadistx);
	else
		draw->perpwalldist = (draw->sidedisty - draw->deltadisty);
	if (draw->side == 0 || draw->side == 2)
		draw->wallx = vars.player.pos_y + draw->perpwalldist * draw->ray_dir_y;
	else
		draw->wallx = vars.player.pos_x + draw->perpwalldist * draw->ray_dir_x;
	draw->wallx -= floor(draw->wallx);
	if (draw->side == 0 || draw->side == 3)
		draw->wallx = 1 - draw->wallx;
}

void	draw_aux2(t_draw *draw, t_vars vars, int hit)
{
	while (hit == 0)
	{
		if (draw->sidedistx < draw->sidedisty)
		{
			draw->sidedistx += draw->deltadistx;
			draw->mapx += draw->stepx;
			if (draw->stepx > 0)
				draw->side = 0;
			else
				draw->side = 2;
		}
		else
		{
			draw->sidedisty += draw->deltadisty;
			draw->mapy += draw->stepy;
			if (draw->stepy > 0)
				draw->side = 1;
			else
				draw->side = 3;
		}
		if (vars.game->board[draw->mapx][draw->mapy] == '1')
			hit = 1;
	}
}

void	draw_aux3(t_draw *draw, t_vars vars)
{
	if (draw->ray_dir_x < 0)
	{
		draw->stepx = -1;
		draw->sidedistx = (vars.player.pos_x - draw->mapx) * draw->deltadistx;
	}
	else
	{
		draw->stepx = 1;
		draw->sidedistx = (draw->mapx + 1 - vars.player.pos_x)
			* draw->deltadistx;
	}
	if (draw->ray_dir_y < 0)
	{
		draw->stepy = -1;
		draw->sidedisty = (vars.player.pos_y - draw->mapy) * draw->deltadisty;
	}
	else
	{
		draw->stepy = 1;
		draw->sidedisty = (draw->mapy + 1 - vars.player.pos_y)
			* draw->deltadisty;
	}	
}

void	draw_aux4(t_draw *draw, t_vars vars)
{
	draw->ray_dir_x = vars.player.dir_x
		+ (vars.player.plane_x * draw->camera_x);
	draw->ray_dir_y = vars.player.dir_y
		+ (vars.player.plane_y * draw->camera_x);
		draw->mapx = (int)(vars.player.pos_x);
	draw->mapy = (int)(vars.player.pos_y);
	if (draw->ray_dir_x == 0)
		draw->deltadistx = 1e10;
	else
		draw->deltadistx = fabs(1 / draw->ray_dir_x);
	if (draw->ray_dir_y == 0)
		draw->deltadisty = 1e10;
	else
		draw->deltadisty = fabs(1 / draw->ray_dir_y);
}

void	wall_sky(t_vars vars, int screen_x, t_data image, t_draw draw)
{
	if (draw.screen_y >= (min_height(draw.perpwalldist)))
	{
		my_mlx_pixel_put(&image, screen_x, draw.screen_y,
			(create_trgb(0, vars.game->rgb.fr,
					vars.game->rgb.fg, vars.game->rgb.fb)));
	}
	else
	{
		my_mlx_pixel_put(&image, screen_x, draw.screen_y,
			(create_trgb(0, vars.game->rgb.cr,
					vars.game->rgb.cg, vars.game->rgb.cb)));
	}
}
