/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:52:49 by marmota           #+#    #+#             */
/*   Updated: 2022/06/10 22:17:21 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"

void	vertical_empty_line(t_game *game, int i)
{
	size_t	j;
	int		space;
	int		start;

	j = 0;
	start = i;
	while (j < ft_strlen(game->board[i]))
	{
		space = 0;
		while (i < game->board_height)
		{
			if (ft_isalnum(game->board[i][j]))
			{
				i = start;
				space = 0;
				if (++j >= ft_strlen(game->board[i]))
					break ;
			}
			else
				++i;
			if (++space == game->board_height - start - 2)
				error_exit("Board has a vertical empty line");
		}
	}
}

void	map_validity(t_game *game, int i, int j)
{
	if (game->board[i][j] != '1' && game->board[i][j] != '0' \
	&& game->board[i][j] != 'N' && game->board[i][j] != 'S' \
	&& game->board[i][j] != 'E' && game->board[i][j] != 'W')
		error_exit("Map has invalid character!");
}

void	check_map_characters(t_vars *vars, t_game *game, int i)
{
	size_t	j;
	int		flag;

	flag = -1;
	while (i < game->board_height)
	{
		j = 0;
		while (j < ft_strlen(game->board[i]))
		{
			if (ft_isalnum(game->board[i][j]))
			{
				map_validity(game, i, j);
				if (game->board[i][j] != '1' && game->board[i][j] != '0')
				{
					flag = game->board[i][j];
					get_player_pos_dir(vars, i, j, flag);
				}
			}
			++j;
		}
		++i;
	}
	if (flag < 0)
		error_exit("Map has more or less than one direction!");
}

void	map_closed(t_game *game, int i, int j)
{
	if (i < game->board_height - 1)
	{
		if (!ft_isalnum(game->board[i - 1][j]) \
		|| !ft_isalnum(game->board[i][j + 1]) \
		|| !ft_isalnum(game->board[i][j - 1]) \
		|| !ft_isalnum(game->board[i + 1][j]))
			if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
				error_exit("Board is not closed1");
	}
	else if (i == game->board_height - 1)
	{
		if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
			error_exit("Board is not closed2");
	}
}

void	check_map(t_vars *vars, t_game *game, int i)
{
	size_t	j;

	while (empty_line(game, i))
		++i;
	vertical_empty_line(game, i);
	check_map_characters(vars, game, i);
	while (i < game->board_height)
	{
		j = 0;
		while (j < ft_strlen(game->board[i]))
		{
			map_closed(game, i, j);
			printf("%c", game->board[i][j]);
			++j;
		}
		printf("\n");
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
