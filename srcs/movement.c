/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:58:00 by mmota             #+#    #+#             */
/*   Updated: 2022/06/10 22:02:46 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

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
