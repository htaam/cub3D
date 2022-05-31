/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:53:17 by marmota           #+#    #+#             */
/*   Updated: 2022/05/31 15:20:58 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include <string.h>

/*	-> Function to confirm map is present in the .cub file
	-> Function to check if map is closed
	-> Function to check chars used in the map are valid

	-> Function to confirm texture paths
	-> Function to contirm rgb values
*/

/* 
-> The reason to use ft_strlen(game->board[i]) instead of
game->board_width[i] is because it gives an error
when the first 2 lines are not correctly printed.
Problem Unknown since the print_board() function
works correctly...

-> Map_isclosed() is validating correctly if the map is indented with spaces
but does not validate correctly if the map is indented with tabs instead
*/

/*	The map_isclosed() function iterate through the map and checks 
	if the limits are all 1s
	The hst and wst variables are used as flags to confirm when 
	we are iterating in the first line or first column
	since they can start anywhere

	the printfs are just for visualization purposes and will be removed after

	if there is an empty line at the end or middle of the map..
	gives a sagmentation fault
*/

//int init_rgb(t_vars *vars, int n, char *s, int c)
//{
//	if (s == 'C')
//	{
//		if (c == 1)
//		{
//			game
//		}
//	}
//}

// Confirm that all id types are found
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

void	check_rgb(t_game *game, int i, char *s)
{
	size_t j;

	j = 0;
	int l = 0;
	int n = 0;
	//int c = 0;
	j = 0;
	while (!ft_strstr(game->board[i], s))
		j++;
	while (!ft_isdigit(game->board[i][j]) && game->board[i][j] != '-')
		++j;
	while (j < ft_strlen(game->board[i]))
	{
		n = ft_atoi(&game->board[i][j]);
		//init_rgb(game, n, s, ++c);
		if (n > 255 || n < 0)
			error_exit("RGB is wrong");
		while (game->board[i][j] != ',' && l < 1)
			++j;
		++j;
		++l;
	}
}

// Find and confirms that all the identifiers types are in the file
// returns the line bellow which there must be a map
int	check_identifiers(t_game *game)
{
	int	idtypes[6];
	int	i;

	i = 0;
	while (i < 6)
		idtypes[i++] = 0;
	i = -1;
	while (game->board[++i])
	{
		if (ft_strstr(game->board[i], "NO ") != 0)
			idtypes[0] += 1;
		if (ft_strstr(game->board[i], "SO ") != 0)
			idtypes[1] += 1;
		if (ft_strstr(game->board[i], "WE ") != 0)
			idtypes[2] += 1;
		if (ft_strstr(game->board[i], "EA ") != 0)
			idtypes[3] += 1;
		if (ft_strstr(game->board[i], "F ") != 0)
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
			return (++i);
		if (ft_strstr(game->board[i], "1111") != 0)
			error_exit("The file is not configured correctly!");
	}
	return (0);
}

// Counts width and height of the board
void	count_board_units(t_game *game, char *board)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 0;
	ret = 1;
	fd = open(board, O_RDONLY);
	if (!fd)
		x_close(game);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) > game->board_width)
		game->board_width = ft_strlen(line);
		game->board_height++;
		++i;
	}
	free(line);
	close(fd);
}

// Read map and stores in the game->board struct
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

// Init necessary board variables
void	init_vars(t_game *game)
{
	game->board = 0;
	game->board_height = 0;
}
