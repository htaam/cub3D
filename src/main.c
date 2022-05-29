/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:56:59 by marmota           #+#    #+#             */
/*   Updated: 2022/05/29 21:42:44 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

int	error_exit(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int		id_line;

	id_line = 0;
	if (check_args(argc, argv) != 0)
		return (1);
	init_vars(&game);
	read_map(&game, argv[1]);
	id_line = check_identifiers(&game);
	if (id_line == 0)
		error_exit("Error\nIdentifiers are not correct!");
	check_map(&game, id_line);
	//print_board(&game, id_line);
	//init_display(&game);
	//mlx_hook(game.mlx_win, 17, (1L << 2), &x_close, &game);
	//render_background(&game);
	//drawPlayer(&game);
	//raycast(&game);
	//mlx_hook(game.mlx_win, 2, (1L << 0), &handle_keypress, &game);
	//mlx_loop(game.mlx);
	return (0);
}
