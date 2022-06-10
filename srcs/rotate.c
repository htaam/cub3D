/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:03:09 by mmota             #+#    #+#             */
/*   Updated: 2022/06/10 22:05:42 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

void	rotate_right(t_vars *vars, double olddirx, double oldplanex)
{
	vars->player.dir_x = vars->player.dir_x
		* cos(-.1) - vars->player.dir_y * sin(-.1);
	vars->player.dir_y = olddirx * sin(-.1) + vars->player.dir_y * cos(-.1);
	oldplanex = vars->player.plane_x;
	vars->player.plane_x = vars->player.plane_x
		* cos(-.1) - vars->player.plane_y * sin(-.1);
	vars->player.plane_y = oldplanex * sin(-.1)
		+ vars->player.plane_y * cos(-.1);
}

void	rotate_left(t_vars *vars, double olddirx, double oldplanex)
{
	vars->player.dir_x = vars->player.dir_x
		* cos(.1) - vars->player.dir_y * sin(.1);
	vars->player.dir_y = olddirx * sin(.1) + vars->player.dir_y * cos(.1);
	oldplanex = vars->player.plane_x;
	vars->player.plane_x = vars->player.plane_x
		* cos(.1) - vars->player.plane_y * sin(.1);
	vars->player.plane_y = oldplanex * sin(.1)
		+ vars->player.plane_y * cos(.1);
}

void	rotate_player(t_vars *vars, int keycode)
{
	double	olddirx;
	double	oldplanex;

	oldplanex = vars->player.plane_x;
	if (keycode == MLX_KEY_RIGHT)
	{
		olddirx = vars->player.dir_x;
		rotate_right(vars, olddirx, oldplanex);
	}
	else if (keycode == MLX_KEY_LEFT)
	{
		olddirx = vars->player.dir_x;
		rotate_left(vars, olddirx, oldplanex);
	}
	draw_stuff(*vars);
}
