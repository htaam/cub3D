/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:34:58 by marmota           #+#    #+#             */
/*   Updated: 2022/06/11 11:44:06 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	init_vars(t_game *game)
{
	game->rgb.cr = -1;
	game->rgb.cg = -1;
	game->rgb.cb = -1;
	game->rgb.fr = -1;
	game->rgb.fg = -1;
	game->rgb.fb = -1;
	game->board = 0;
	game->board_height = 0;
}

void	print_board(t_game *game, int i)
{
	size_t	j;

	while (i < game->board_height)
	{
		j = 0;
		while (j < ft_strlen(game->board[i]))
		{
			printf("%c", game->board[i][j]);
			++j;
		}
		++i;
		printf("\n");
	}
}

int	*zero_array(int *array)
{
	int	i;

	i = 0;
	while (i < 6)
		array[i++] = 0;
	return (array);
}
