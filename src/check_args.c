/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:36:51 by marmota           #+#    #+#             */
/*   Updated: 2022/05/30 16:48:29 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	check_args(int argc, char *argv[])
{
	if (argc != 2)
		error_exit("Not enough arguments!");
	check_extension(argv[1]);
	return (EXIT_SUCCESS);
}

int	check_extension(char *ext)
{
	size_t		i;
	char		*str;
	size_t		size;

	i = -1;
	size = ft_strlen(&ext[i + 1]);
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
