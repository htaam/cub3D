/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:56:59 by marmota           #+#    #+#             */
/*   Updated: 2022/05/30 12:26:53 by marmota          ###   ########.fr       */
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

	
	t_vars		vars;
    void		*aux;

	aux = &vars;
	init_stuff(&vars);
	vars.game = &game;
	vars.player.pos_x = 20;
	vars.player.pos_y = 20;
	vars.player.dir_x = -1;
	vars.player.dir_y = 0;
	vars.player.plane_x = 0;
	vars.player.plane_y = 0.5;
	draw_stuff(vars);
 	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, 0L, red_cross, aux);
	mlx_hook(vars.win, 2, 0L, key_hook, aux);
	mlx_loop(vars.mlx);
 
    mlx_loop(vars.mlx);		
	return (0);
}
