/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:34:58 by marmota           #+#    #+#             */
/*   Updated: 2022/05/27 22:35:47 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

// Prints board
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

// Exits the game and frees memory
int	x_close(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->board_height)
		if (game->board && game->board[i])
			free(game->board[i]);
	if (game->board)
		free(game->board);
	if (game->mlx_win)
		free(game->mlx_win);
	if (game->mlx)
		free(game->mlx);
	exit(EXIT_SUCCESS);
}
