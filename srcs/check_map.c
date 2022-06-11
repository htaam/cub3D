/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:52:49 by marmota           #+#    #+#             */
/*   Updated: 2022/06/11 18:45:29 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (++space == game->board_height - start - 1)
				error_exit(game, "Board has a vertical empty line");
		}
	}
}

void	map_validity(t_game *game, int i, int j)
{
	if (game->board[i][j] != '1' && game->board[i][j] != '0' \
	&& game->board[i][j] != 'N' && game->board[i][j] != 'S' \
	&& game->board[i][j] != 'E' && game->board[i][j] != 'W')
		error_exit(game, "Map has invalid character!");
}

void	check_map_characters(t_vars *vars, t_game *game, int i)
{
	size_t	j;
	int		flag;

	flag = -1;
	while (i < game->board_height)
	{
		j = -1;
		while (++j < ft_strlen(game->board[i]))
		{
			if (ft_isalnum(game->board[i][j]))
			{
				map_validity(game, i, j);
				if (game->board[i][j] != '1' && game->board[i][j] != '0')
				{	
					if (flag != -1)
						error_exit(game, "Invalid map!");
					flag = game->board[i][j];
					get_player_pos_dir(vars, i, j, flag);
				}
			}
		}
		++i;
	}
	if (flag < 0)
		error_exit(game, "Map has more or less than one direction!");
}

void	map_closed(t_game *game, int i, int j, int id)
{
	if (game->board[i][j] == '0' || game->board[i][j] == 'W'
		|| game->board[i][j] == 'N' || game->board[i][j] == 'E'
		|| game->board[i][j] == 'S')
	{
		if (check_around(game, i, j, id) == 0)
			error_exit(game, "invalid map");
	}
}

void	check_map(t_vars *vars, t_game *game, int i)
{
	size_t	j;
	int		id;

	while (empty_line(game, i))
		++i;
	vertical_empty_line(game, i);
	check_map_characters(vars, game, i);
	id = i;
	while (i < game->board_height)
	{
		j = -1;
		while (++j < ft_strlen(game->board[i]))
			map_closed(game, i, j, id);
		++i;
		while (i + 1 < game->board_height && empty_line(game, i))
		{
			++i;
			if (!empty_line(game, i))
				error_exit(game, "Map has no passage!");
		}
	}
}
