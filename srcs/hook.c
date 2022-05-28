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
	if (keycode == MLX_KEY_ESC)
		exit (0);
	if (keycode == MLX_KEY_LEFT || keycode == MLX_KEY_RIGHT)
		rotate_player(vars, keycode);
	if (keycode == MLX_KEY_W)
		forward(vars);
	if (keycode == MLX_KEY_S)
		backward(vars);
	if (keycode == MLX_KEY_D)
		right(vars);
	if (keycode == MLX_KEY_A)
		left(vars);
	return (keycode);
}

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
