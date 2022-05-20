#include "cub3d.h"
#include "stdio.h"
#include <string.h>

/*	-> Function to confirm map is present in the .cub file
	-> Function to check if map is closed
	-> Function to check chars used in the map are valid

	-> Function to confirm texture paths
	-> Function to contirm rgb values
*/

// Confirm that all id types are found
int all_idtypes(int *idtypes)
{
	int i;

	i = -1;
	while (++i < 6)
	{
		if (idtypes[i] != 1)
			return (0);
	}
	return (1);
}

// Find and confirms taht all the identifiers types are in the file
// returns the line bellow which there must be a map
int	check_identifiers(t_game *game)
{
	int idtypes[6];
	int i;

	i = 0;
	while (i < 6)
		idtypes[i++] = 0;
	i = 0;
	while (game->board[i])
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
			idtypes[4] += 1;
		if (ft_strstr(game->board[i], "C ") != 0)
			idtypes[5] += 1;
		if (all_idtypes(idtypes))
			return (++i);	
		++i;
	}
	return (0);
}

// Counts width and height of the board
void	count_board_units(t_game *game, char *board)
{
	int		fd;
	char	*line;
	int i = 0;

	fd = open(board, O_RDONLY);
	if (!fd)
		x_close(game);
	while (get_next_line(fd, &line))
	{
		game->board_width[i] = ft_strlen(line);
		++game->board_height;
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
		if (ft_strlen(line) > 0)
		{
			game->board[y] = line;
			y++;
		}
		else
			free(line);
	}
	close(fd);
}

// Init necessary board variables
void	init_vars(t_game *game)
{
	game->board = 0;
	game->board_height = 0;
}