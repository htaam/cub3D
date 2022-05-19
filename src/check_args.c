#include "cub3d.h"

// Checks that an argument was added after the program name
int	check_args(int argc, char *argv[])
{
	if (argc != 2)
		error_exit("Not enough arguments!");
	check_extension(argv[1]);
	check_argument_file(argv[1]);
	return(EXIT_SUCCESS);
}

// Checks that the argument extension is correct
int check_extension(char *ext)
{
	int i;

	i = -1;
	while (ext[++i])
	{
		if (ext[i] == '.' && i++)
			if (ft_strncmp(&ext[i],"cub", 3) != 0)
				error_exit("File has a wrong extension!");
	}
	return (EXIT_SUCCESS);
}

// Check file passed as an argument can be open
int	check_argument_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit("File can't be open or doesn't exist!");
	else
		close(fd);
	return (EXIT_SUCCESS);
}