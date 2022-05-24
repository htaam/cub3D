/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:52:49 by marmota           #+#    #+#             */
/*   Updated: 2022/05/24 18:31:21 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include <string.h>

int	empty_line(t_game *game, int i)
{
	size_t	j;

	j = -1;
	if (ft_strlen(game->board[i]) <= 0)
		return (1);
	while (++j < ft_strlen(game->board[i]))
	{
		if (ft_isprint(game->board[i][j]))
			return (0);
	}
	return (1);
}

void	map_isclosed(t_game *game, int i)
{
	int		hst;
	int		wst;
	size_t	j;

	hst = 0;
	wst = 0;
	while (empty_line(game, i))
		++i;
	while (i < game->board_height)
	{
		j = 0;
		while (j < ft_strlen(game->board[i]))
		{
			if (!hst || i == game->board_height - 1)
				if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
					error_exit("Board is not closed1");
			if (!wst || j == ft_strlen(game->board[i]))
				if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
					error_exit("Board is not closed2");
			if (!ft_isalnum(game->board[i - 1][j])
			|| !ft_isalnum(game->board[i + 1][j])
			|| !ft_isalnum(game->board[i][j + 1])
			|| !ft_isalnum(game->board[i][j - 1]))
				if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
					error_exit("Board is not closed3");
			printf("%c", game->board[i][j]);
			wst = 1;
			++j;
		}
		printf("\n");
		hst = 1;
		++i;
		while (empty_line(game, i) && ++i < game->board_height)
			if (!empty_line(game, i))
				error_exit("Map has no passage!");
	}
	printf("map is valid");
}
