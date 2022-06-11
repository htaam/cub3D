/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:53:17 by marmota           #+#    #+#             */
/*   Updated: 2022/06/11 13:47:04 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include <string.h>

char	*get_texture_path(t_game *game, int i, char c)
{
	char	*path;
	int		fd;

	path = game->board[i];
	while (*path != c)
		path++;
	path += 2;
	if (ft_strnstr(path, " ./", 3))
		path += 3;
	fd = open(path, O_RDONLY);
	if (fd > -1)
		close(fd);
	else
		error_exit(game, "Invalid texture");
	if (check_texture_extension(game, path))
		return (path);
	return (path);
}

int	check_textures(t_game *game, int *idtypes, int i)
{
	if (ft_strnstr(game->board[i], "NO ", 3) != 0)
	{
		game->texture.path[2] = get_texture_path(game, i, 'N');
		idtypes[0] += 1;
	}
	if (ft_strnstr(game->board[i], "SO ", 3) != 0)
	{
		game->texture.path[0] = get_texture_path(game, i, 'S');
		idtypes[1] += 1;
	}
	if (ft_strnstr(game->board[i], "WE ", 3) != 0)
	{
		game->texture.path[3] = get_texture_path(game, i, 'W');
		idtypes[2] += 1;
	}
	if (ft_strnstr(game->board[i], "EA ", 3) != 0)
	{
		game->texture.path[1] = get_texture_path(game, i, 'E');
		idtypes[3] += 1;
	}
	return (i);
}

int	check_identifiers(t_game *game, int *idtypes)
{
	int	i;

	i = -1;
	while (game->board[++i])
	{
		i = check_textures(game, idtypes, i);
		if (ft_strnstr(game->board[i], "F ", 2) != 0)
		{
			idtypes[4] += 1;
			check_rgb(game, i, "F ");
		}
		if (ft_strstr(game->board[i], "C ") != 0)
		{
			idtypes[5] += 1;
			check_rgb(game, i, "C ");
		}
		if (all_idtypes(idtypes))
		{
			return (++i);
		}
		if (ft_strstr(game->board[i], "1111") != 0)
			error_exit(game, "The file is not configured correctly!");
	}
	return (0);
}

void	count_board_units(t_game *game, char *board)
{
	int		fd;
	char	*line;
	int		ret;

	ret = 1;
	fd = open(board, O_RDONLY);
	if (!fd)
		error_exit(game, "Map can't be open");
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		game->board_height++;
		free(line);
	}
	close(fd);
}

void	read_map(t_game *game, char *board)
{
	int		fd;
	char	*line;
	int		ret;
	int		y;

	y = 0;
	count_board_units(game, board);
	ret = 1;
	fd = open(board, O_RDONLY);
	game->board = ft_calloc(game->board_height, sizeof(char *));
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		game->board[y] = line;
		y++;
	}
	ret = get_next_line(fd, &line);
	if (ret != 0)
		game->board[y] = line;
	free(line);
	close(fd);
}
