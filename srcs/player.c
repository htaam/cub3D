/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:12:14 by mmota             #+#    #+#             */
/*   Updated: 2022/06/10 22:26:54 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

void	get_player_pos_south(t_vars *vars)
{		
	vars->player.dir_x = vars->player.dir_x * cos(PI) \
	- vars->player.dir_y * sin(PI);
	vars->player.dir_y = -1 * sin(PI) + vars->player.dir_y * cos(PI);
	vars->player.plane_x = vars->player.plane_x * cos(PI) \
	- vars->player.plane_y * sin(PI);
	vars->player.plane_y = 0 * sin(PI) + vars->player.plane_y * cos(PI);
}

void	get_player_pos_east(t_vars *vars)
{
	vars->player.dir_x = vars->player.dir_x * cos(-PI / 2) \
	- vars->player.dir_y * sin(-PI / 2);
	vars->player.dir_y = -1 * sin(-PI / 2) + vars->player.dir_y \
	* cos(-PI / 2);
	vars->player.plane_x = vars->player.plane_x * cos(-PI / 2) \
	- vars->player.plane_y * sin(-PI / 2);
	vars->player.plane_y = 0 * sin(-PI / 2) + \
	vars->player.plane_y * cos(-PI / 2);
}

void	get_player_pos_west(t_vars *vars)
{
	vars->player.dir_x = vars->player.dir_x * cos(PI / 2) \
	- vars->player.dir_y * sin(PI / 2);
	vars->player.dir_y = -1 * sin(PI / 2) + vars->player.dir_y \
	* cos(PI / 2);
	vars->player.plane_x = vars->player.plane_x * cos(PI / 2) \
	- vars->player.plane_y * sin(PI / 2);
	vars->player.plane_y = 0 * sin(PI / 2) + \
	vars->player.plane_y * cos(PI / 2);
}

void	get_player_pos_dir(t_vars *vars, int i, int j, char dir)
{
	vars->player.pos_x = i + 0.5;
	vars->player.pos_y = j + 0.5;
	vars->player.dir_x = -1;
	vars->player.dir_y = 0;
	vars->player.plane_x = 0;
	vars->player.plane_y = 0.5;
	if (dir == 'S')
		get_player_pos_south(vars);
	else if (dir == 'E')
		get_player_pos_east(vars);
	else if (dir == 'W')
		get_player_pos_west(vars);
}
