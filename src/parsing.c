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

/*	The map_isclosed() function iterate through the map and checks if the limits are all 1s
	The hst and wst variables are used as flags to confirm when we are iterating in the first line or first column
	since they can start anywhere

	the printfs are just for visualization purposes and will be removed after

	if there is an empty line at the end or middle of the map..
	gives a sagmentation fault
*/

int empty_line(t_game *game, int i)
{
	if (game->board_width[i] <= 0)
	{
		printf("%i\n", game->board_width[i]);
		return (0);
	}
	return (1);
}


void map_isclosed(t_game *game, int i)
{
	int hst;
	int wst;
	size_t j;

	hst = 0;
	wst = 0;
	printf("%i %s\n", i, game->board[i]);
	while (empty_line(game, i))
		++i;
	
	while (i < game->board_height)
	{
		if (empty_line(game, i))
			error_exit("Board has empty lines!");
		j = 0;
		while (j < ft_strlen(game->board[i]))
		{
			if (!hst || i == game->board_height)
			{
				if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
					error_exit("Board is not closed1");
			}
			// check first line
			else if (!wst || j == ft_strlen(game->board[i]))
			{
				if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
					error_exit("Board is not closed2");
			}
			else if (!ft_isalnum(game->board[i - 1][j]) || !ft_isalnum(game->board[i][j + 1]) || !ft_isalnum(game->board[i][j - 1]))
			{
				if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
					error_exit("Board is not closed3");
			}
			// check in-between indentations
			if (i == game->board_height)
			{
				if (ft_isalnum(game->board[i][j]) && game->board[i][j] != '1')
				{
					if (game->board[i][j] != '1')
						error_exit("Board is not closed4");
				}
			}
			printf("%c", game->board[i][j]);
			wst = 1;
			++j;
		}
		if (j < 4)
			error_exit("Map has not enough passage!");
		printf("\n");
		hst = 1;
		++i;
	}
	printf("map is valid");
}

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

// Find and confirms that all the identifiers types are in the file
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