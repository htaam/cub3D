#include "cub3d.h"

void	draw_aux1(t_draw *draw, t_vars vars)
{
	if (draw->side == 0 || draw->side == 2)
			draw->perpWallDist = (draw->sideDistx - draw->deltaDistx);
	else
		draw->perpWallDist = (draw->sideDisty - draw->deltaDisty);
	if (draw->side == 0 || draw->side == 2)
		draw->wallX = vars.player.pos_y + draw->perpWallDist * draw->ray_dir_y;
	else
		draw->wallX = vars.player.pos_x + draw->perpWallDist * draw->ray_dir_x;
	draw->wallX -= floor(draw->wallX);
	if (draw->side == 0 || draw->side == 3)
		draw->wallX = 1 - draw->wallX;
}

void	draw_aux2(t_draw *draw, t_vars vars, int hit)
{
	while (hit == 0)
	{
		if (draw->sideDistx < draw->sideDisty)
		{
			draw->sideDistx += draw->deltaDistx;
			draw->mapx += draw->stepx;
			if (draw->stepx > 0)
				draw->side = 0;
			else
				draw->side = 2;
		}
		else
		{
			draw->sideDisty += draw->deltaDisty;
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
		draw->sideDistx = (vars.player.pos_x - draw->mapx) * draw->deltaDistx;
	}
	else
	{
		draw->stepx = 1;
		draw->sideDistx = (draw->mapx + 1 - vars.player.pos_x)
			* draw->deltaDistx;
	}
	if (draw->ray_dir_y < 0)
	{
		draw->stepy = -1;
		draw->sideDisty = (vars.player.pos_y - draw->mapy) * draw->deltaDisty;
	}
	else
	{
		draw->stepy = 1;
		draw->sideDisty = (draw->mapy + 1 - vars.player.pos_y)
			* draw->deltaDisty;
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
		draw->deltaDistx = 1e10;
	else
		draw->deltaDistx = fabs(1 / draw->ray_dir_x);
	if (draw->ray_dir_y == 0)
		draw->deltaDisty = 1e10;
	else
		draw->deltaDisty = fabs(1 / draw->ray_dir_y);
}
