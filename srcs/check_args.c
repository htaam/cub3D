/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:36:51 by marmota           #+#    #+#             */
/*   Updated: 2022/06/10 20:36:19 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	check_args(int argc, char *argv[])
{
	if (argc != 2)
		error_exit("Not enough arguments!");
	if (access(argv[1], F_OK) != -1)
		check_map_extension(argv[1]);
	else
		error_exit("map does not exist!");
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
					error_exit("File has wrong extension!");
				else
					return (EXIT_SUCCESS);
			}
		}
	}
	error_exit("File has wrong extension!");
	return (0);
}

int	check_texture_extension(char *ext)
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
				error_exit("File has wrong extension!");
			else
				return (1);
		}
	}
	return (0);
}