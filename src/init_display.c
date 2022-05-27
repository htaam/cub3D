/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:38:12 by marmota           #+#    #+#             */
/*   Updated: 2022/05/27 22:40:10 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

void	init_display(t_game *game)
{
	game->player.posX = 22;
	game->player.posY = 12;
	game->player.dirX = -1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.66;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, \
	screenWidth, screenHeight, "Cub3d");
}
