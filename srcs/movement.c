#include "cub3d.h"

void	rotate_player(t_vars *vars, int keycode)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == MLX_KEY_RIGHT)
	{
		olddirx = vars->player.dir_x;
		vars->player.dir_x = vars->player.dir_x
			* cos(-.1) - vars->player.dir_y * sin(-.1);
		vars->player.dir_y = olddirx * sin(-.1) + vars->player.dir_y * cos(-.1);
		oldplanex = vars->player.plane_x;
		vars->player.plane_x = vars->player.plane_x
			* cos(-.1) - vars->player.plane_y * sin(-.1);
		vars->player.plane_y = oldplanex * sin(-.1)
			+ vars->player.plane_y * cos(-.1);
	}
	else if (keycode == MLX_KEY_LEFT)
	{
		olddirx = vars->player.dir_x;
		vars->player.dir_x = vars->player.dir_x
			* cos(.1) - vars->player.dir_y * sin(.1);
		vars->player.dir_y = olddirx * sin(.1) + vars->player.dir_y * cos(.1);
		oldplanex = vars->player.plane_x;
		vars->player.plane_x = vars->player.plane_x
			* cos(.1) - vars->player.plane_y * sin(.1);
		vars->player.plane_y = oldplanex * sin(.1)
			+ vars->player.plane_y * cos(.1);
	}
	draw_stuff(*vars);
}

void	forward(t_vars *vars)
{
	if (!(vars->game->board[(int)(vars->player.pos_x
				+ vars->player.dir_x
				* 0.2 * 2)][(int)vars->player.pos_y] == '1'))
	{
		vars->player.pos_x = vars->player.pos_x + vars->player.dir_x * 0.2;
	}
	if (!(vars->game->board[(int)vars->player.pos_x][(int)(vars->player.pos_y
			+ vars->player.dir_y * 0.2 * 2)] == '1'))
	{
		vars->player.pos_y = vars->player.pos_y
			+ vars->player.dir_y * 0.2;
	}
	draw_stuff(*vars);
}

void	backward(t_vars *vars)
{
	if (!(vars->game->board[(int)(vars->player.pos_x
				- vars->player.dir_x * 0.2
				* 2)][(int)vars->player.pos_y] == '1'))
	{
		vars->player.pos_x = vars->player.pos_x - vars->player.dir_x * 0.2;
	}
	if (!(vars->game->board[(int)vars->player.pos_x][(int)(vars->player.pos_y
			- vars->player.dir_y * 0.2 * 2)] == '1'))
	{
		vars->player.pos_y = vars->player.pos_y - vars->player.dir_y * 0.2;
	}
	draw_stuff(*vars);
}

void	right(t_vars *vars)
{
	double	turnx;
	double	turny;

	turnx = vars->player.dir_x * cos(PI / 2)
		- vars->player.dir_y * sin(PI / 2);
	turny = vars->player.dir_x * sin(PI / 2)
		+ vars->player.dir_y * cos(PI / 2);
	if (!(vars->game->board[(int)(vars->player.pos_x
				- turnx * 0.2 * 2)][(int)vars->player.pos_y] == '1'))
	{
		vars->player.pos_x = vars->player.pos_x - turnx * 0.2;
	}
	if (!(vars->game->board[(int)vars->player.pos_x][(int)(vars->player.pos_y
			- turny * 0.2 * 2)] == '1'))
	{
		vars->player.pos_y = vars->player.pos_y
			- turny * 0.2;
	}
	draw_stuff(*vars);
}

void	left(t_vars *vars)
{
	double	turnx;
	double	turny;

	turnx = vars->player.dir_x * cos(-PI / 2)
		- vars->player.dir_y * sin(-PI / 2);
	turny = vars->player.dir_x * sin(-PI / 2)
		+ vars->player.dir_y * cos(-PI / 2);
	if (!(vars->game->board[(int)(vars->player.pos_x
				- turnx * 0.2 * 2)][(int)vars->player.pos_y] == '1'))
	{
		vars->player.pos_x = vars->player.pos_x - turnx * 0.2;
	}
	if (!(vars->game->board[(int)vars->player.pos_x][(int)(vars->player.pos_y
			- turny * 0.2 * 2)] == '1'))
	{
		vars->player.pos_y = vars->player.pos_y - turny * 0.2;
	}
	draw_stuff(*vars);
}
