/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:33:03 by marmota           #+#    #+#             */
/*   Updated: 2022/05/27 23:00:36 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

// Display color
//int	create_trgb(int t, int r, int g, int b)
//{
//	return (t << 24 | r << 16 | g << 8 | b);
//}
//
//void	drawplayer(t_game *game)
//{
//	game->player.width = 8;
//	game->player.height = 8;
//	int color = create_trgb(0, 255, 204, 0);
//	int i = game->player.posY;
//	int j;
//	if (game->mlx_win == NULL)
//		return ;
//	while (i < game->player.width + game->player.posY)
//	{
//		j = game->player.posX;
//		while (j < game->player.height + game->player.posX)
//			mlx_pixel_put(game->mlx, game->mlx_win, j++, i, color);
//		++i;
//	}
//}
//
//void render_background(t_game *game)
//{
//	int color = create_trgb(30, 30, 30, 30);
//	int i = 0;
//	int j;
//	if (game->mlx_win == NULL)
//		return ;
//	while (i < 512)
//	{
//		j = 0;
//		while (j < 1024)
//		{
//			mlx_pixel_put(game->mlx, game->mlx_win, j++, i, color);	
//		}
//		++i;
//	}
//}

// Calculate ray position and direction
//void	raycast(t_game *game)
//{
//	int		x;
//	int		w;
//	double	cameraX;
//	double	rayDirX;
//	double	rayDirY;
//	
//	x = 0;
//	w = 0;
//	while (x < w)
//	{
//		cameraX = 2 * x / (double)w - 1;
//		rayDirX = game->player.dirX + game->player.planeX * cameraX;
//		rayDirY = game->player.dirY + game->player.planeY * cameraX;
//		++x;
//	}
//	printf("%f, %f\n", rayDirX, rayDirY );
//}
