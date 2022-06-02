/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:12:47 by marmota           #+#    #+#             */
/*   Updated: 2022/06/02 13:56:51 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include <string.h>

void	init_rgb(t_game *game, int n, char *s, int c)
{
	if (ft_strchr(s, 'C') == 0)
	{
		if (c == 1)
			game->rgb.cr = n;
		else if (c == 2)
			game->rgb.cg = n;
		else if (c == 3)
			game->rgb.cb = n;
	}
	else if (ft_strchr(s, 'F') == 0)
	{
		if (c == 1)
			game->rgb.fr = n;
		else if (c == 2)
			game->rgb.fg = n;
		else if (c == 3)
			game->rgb.fb = n;
	}
	if (n < 0 || n > 255)
		error_exit("Invalid RGB value");
	printf("rgb: %i,\n", n);
}

void	check_rgb(t_game *game, int i, char *s)
{
	size_t	j;
	int		n;
	int		c;

	j = 0;
	n = 0;
	c = 0;
	j = 0;
	while (!ft_strstr(game->board[i], s))
		j++;
	while (!ft_isdigit(game->board[i][j]) && game->board[i][j] != '-')
		++j;
	while (j < ft_strlen(game->board[i]) && ++c <= 3)
	{
		n = ft_atoi(&game->board[i][j]);
		init_rgb(game, n, s, c);
		if (n > 255 || n < 0)
			error_exit("RGB is wrong");
		while (game->board[i][j] != ',')
			++j;
		++j;
	}
	if (c != 3)
		error_exit("No RGB value submited!");
}