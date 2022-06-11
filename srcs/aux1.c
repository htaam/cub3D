/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:44:13 by tmatias           #+#    #+#             */
/*   Updated: 2022/06/11 18:44:01 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	check_around(t_game *game, int i, int j, int id)
{
	if (i == id || id == game->board_height
		|| i == 0 || id == (int)ft_strlen(game->board[i]))
		return (0);
	if ((!ft_isalnum(game->board[i - 1][j]))
		|| !ft_isalnum(game->board[i][j + 1])
		|| (!ft_isalnum(game->board[i][j - 1]))
		|| (!ft_isalnum(game->board[i + 1][j])))
	{
		if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
			return (0);
	}
	return (1);
}
