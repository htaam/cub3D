#include "cub3d.h"

int	check_args(int argc, char *argv[])
{
	if (argc != 2)
		error_exit("Not enough arguments!");
	check_extension(argv[1]);
	return(EXIT_SUCCESS);
}

int check_extension (char *ext)
{
	int i;

	i = -1;
	while (ext[++i])
	{
		if (ext[i] == '.' && i++)
			if (ft_strncmp(&ext[i],"cub", 3) != 0)
				error_exit("File has wrong extension!");
	}
	return (EXIT_SUCCESS);
}