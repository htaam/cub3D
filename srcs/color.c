/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:12:47 by marmota           #+#    #+#             */
/*   Updated: 2022/06/10 21:47:37 by mmota            ###   ########.fr       */
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
		error_exit("Error\nInvalid RGB value");
}

void	rgb_validity(t_game *game, int i, size_t j, int c)
{
	while (ft_isdigit(game->board[i][j]))
		++j;
	if (c != 4)
		error_exit("Error\nNo RGB value submited!");
	if (j < ft_strlen(game->board[i]))
		error_exit("Error\nToo many values");
}

int	check_rgb_submit(t_game *game, int i, char *s)
{
	size_t	j;

	j = 0;
	while (!ft_strstr(game->board[i], s))
		j++;
	while (!ft_isdigit(game->board[i][j]) && game->board[i][j] != '-')
	{
		if (j != ft_strlen(game->board[i]))
			++j;
		else
			error_exit("Error\nNo value submited");
	}
	return (j);
}

void	check_rgb(t_game *game, int i, char *s)
{
	size_t	j;
	int		n;
	int		c;

	c = 0;
	j = check_rgb_submit(game, i, s);
	while (++c < 4)
	{
		n = ft_atoi(&game->board[i][j]);
		init_rgb(game, n, s, c);
		if (c < 3)
		{
			while (game->board[i][j] != ',')
			{
				if (ft_isdigit(game->board[i][j]))
					++j;
				else
					error_exit("Error\nNo RGB value submited");
			}
			if (ft_isdigit(game->board[i][j + 1]) == 0)
				error_exit("Error\nToo many comas");
		}
		++j;
	}
	rgb_validity(game, i, j, c);
}
