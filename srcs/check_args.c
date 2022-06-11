/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:36:51 by marmota           #+#    #+#             */
/*   Updated: 2022/06/11 17:32:19 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	check_args(int argc, char *argv[])
{
	if (argc != 2)
		exit_end("Invalid number of arguments!");
	if (access(argv[1], F_OK) != -1)
		check_map_extension(argv[1]);
	else
		exit_end("map does not exist!");
	return (EXIT_SUCCESS);
}

int	check_map_extension(char *ext)
{
	size_t		i;
	char		*str;
	size_t		size;

	i = -1;
	size = ft_strlen(ext);
	while (++i < size)
	{
		if (ext[i] == '.')
		{
			i++;
			str = &ext[i];
			if (ft_strlen(str) == 3)
			{
				if (ft_strncmp(&ext[i], "cub", 3) != 0)
					exit_end("Invalid map extension");
				else
					return (EXIT_SUCCESS);
			}
		}
	}
	exit_end("File has wrong extension!");
	return (0);
}

int	check_texture_extension(t_game *game, char *ext)
{
	size_t		i;
	char		*str;
	size_t		size;

	i = -1;
	size = ft_strlen(ext);
	while (++i < size)
	{
		if (ext[i] == '.')
		{
			str = &ext[i];
			if (ft_strnstr(str, ".xpm", 4) == 0)
				error_exit(game, "File has wrong extension!");
			else
				return (1);
		}
	}
	return (0);
}

int	all_idtypes(int *idtypes)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (idtypes[i] != 1)
			return (0);
	}
	return (1);
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
