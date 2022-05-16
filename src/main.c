#include "cub3d.h"
#include "stdio.h"

// Prints board
void print_board(t_game *game)
{
    int i = -1;
	while (++i < game->board_height)
        printf("%s\n", game->board[i]);
}

// Exits the game and frees memory
void	game_exit(t_game *game, char *message)
{
	int	i;

	ft_putstr_fd(message, 1);
	i = -1;
	while (++i < game->board_height)
		if (game->board && game->board[i])
			free(game->board[i]);
	if (game->board)
		free(game->board);
	if (game->mlx_win)
		free(game->mlx_win);
	if (game->mlx)
		free(game->mlx);
	exit(EXIT_SUCCESS);
}

// Counts width and height of the board
void	count_board_units(t_game *game, char *board)
{
	int		fd;
	char	*line;

	game->board_width = 0;
	fd = open(board, O_RDONLY);
	if (!fd)
		game_exit(game, "No board");
	while (get_next_line(fd, &line))
	{
		if (!game->board_width)
			game->board_width = ft_strlen(line);
		++game->board_height;
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
			game->board[y++] = line;
		else
			free(line);
	}
	close(fd);
}

// Init necessary board variables
void	init_vars(t_game *game)
{
	game->board = 0;
	game->board_width = 0;
	game->board_height = 0;
}

// Init necessary variables
// Read map .ber file
// Print board to check it was saved correctly
// Exit program and frees memory 
int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		return (0);
	init_vars(&game);
	read_map(&game, argv[1]);
    print_board(&game);
    game_exit(&game, "EXIT\n");
	return (0);
}