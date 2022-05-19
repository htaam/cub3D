#include "cub3d.h"

int	check_map(char *file, t_game *game)
{
	int fd;
	char *line;
	(void) game;
	int i = 0;

	fd = open(file, O_RDONLY);
	
	while (get_next_line(fd, &line))
	{
		if (line[0] == '1')
			break;
	}

	while (line[i])
	{
		if (line[i] != '1')
			error_exit("Map is not closed");
		++i;
	}
	printf("%s\n", line);
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] <= 32)
			++i;
		if (line[i] == '1' && line[ft_strlen(line) - 1] == '1')
			printf("%s\n", line);
		else
			error_exit("Map is not closed");
	}
	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			error_exit("Map is not closed");
		++i;
	}
	printf("%s\n", line);
	return (EXIT_SUCCESS);
}