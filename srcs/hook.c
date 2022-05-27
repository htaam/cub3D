/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:48:36 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/24 17:36:37 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 53)
		exit (0);
	if (keycode == 123 || keycode == 124)
		rotate_player(vars, keycode);
	if (keycode == 13)
		forward(vars);
	if (keycode == 1)
		backward(vars);
	return (keycode);
}

/* w = 13	a = 0	d = 2	s = 1	<- =  123	-> = 124*/
int	mouse_hook(int mouse_code, int x, int y, t_vars *vars)
{
	(void)vars;
	if (x && y)
		;
	if (mouse_code == 4)
		;
	if (mouse_code == 5)
		;
	return (mouse_code);
}

int	red_cross(void)
{
	exit(0);
	return (0);
}
