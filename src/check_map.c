/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:52:49 by marmota           #+#    #+#             */
/*   Updated: 2022/05/25 19:14:59 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include <string.h>

int	vertical_empty_line(t_game *game, int i)
{
	size_t j = 0;
	int space;
	int start = i;
	while (j < ft_strlen(game->board[i]))
	{
		space = 0;
		while (i < game->board_height)
		{
			printf(" space: %i height: %i char : %c\n", space, game->board_height - start, game->board[i][j]);
			if (ft_isalnum(game->board[i][j]))
			{
				if (j < game->board_width)
				{
					++j;
				}
				i = start;
				space = 0;
			}
			else
			{
				++space;
				++i;
				if (space == game->board_height - start)
					error_exit("Board has a vertical empty line");
			}
		}
		j++;
	}
	return (0);
}

int	empty_line(t_game *game, int i)
{
	size_t	j;

	j = -1;
	if (ft_strlen(game->board[i]) <= 0)
		return (1);
	while (++j < ft_strlen(game->board[i]))
	{
		if (ft_isalnum(game->board[i][j]))
			return (0);
	}
	return (1);
}

void	map_isclosed(t_game *game, int i)
{
	size_t	j;

	while (empty_line(game, i))
		++i;
	vertical_empty_line(game, i);
	while (i < game->board_height)
	{
		j = 0;
		while (j < ft_strlen(game->board[i]))
		{
			if (i < game->board_height - 1)
			{
				if (!ft_isalnum(game->board[i - 1][j]) || !ft_isalnum(game->board[i][j + 1]) || !ft_isalnum(game->board[i][j - 1]) || !ft_isalnum(game->board[i + 1][j]))
					if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
						error_exit("Board is not closed1");
			}
			else if (i == game->board_height - 1)
			{
				if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
					error_exit("Board is not closed2");
			}
			//printf("%c", game->board[i][j]);
			++j;
		}
		//printf("\n");
		++i;
		while (i + 1 < game->board_height && empty_line(game, i))
		{
			++i;
			if (!empty_line(game, i))
				error_exit("Map has no passage!");
		}
	}
	printf("map is valid");
}