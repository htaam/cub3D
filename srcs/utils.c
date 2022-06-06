/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:34:58 by marmota           #+#    #+#             */
/*   Updated: 2022/06/06 23:30:07 by marmota          ###   ########.fr       */
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


int	error_exit(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

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

int *zero_array(int *array)
{
	int i;
	
	i = 0;
	while (i < 6)
		array[i++] = 0;
	return (array);
}