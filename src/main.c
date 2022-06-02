/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:56:59 by marmota           #+#    #+#             */
/*   Updated: 2022/06/02 13:51:54 by marmota          ###   ########.fr       */
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
	t_vars		vars;
    void		*aux;
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
	aux = &vars;
	init_stuff(&vars);
	vars.game = &game;
	vars.player.pos_x = game.player.pos_x;
	vars.player.pos_y = game.player.pos_y;
	vars.player.dir_x = -1;
	vars.player.dir_y = 0;
	vars.player.plane_x = 0;
	vars.player.plane_y = 0.5;
	draw_stuff(vars);
 	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, (1L << 2), red_cross, aux);
	mlx_hook(vars.win, 2, (1L << 0), key_hook, aux);
	mlx_loop(vars.mlx);	
	return (0);
}
