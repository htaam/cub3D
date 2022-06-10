/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:59:12 by mmota             #+#    #+#             */
/*   Updated: 2022/06/10 22:42:32 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_stuff(t_vars *vars)
{
	int	x_max;
	int	y_max;

	x_max = SCREENHEIGHT;
	y_max = SCREENWIDTH;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x_max,
			y_max, "A");
	vars->image.img = mlx_new_image(vars->mlx, x_max,
			y_max);
	vars->image.addr = mlx_get_data_addr(vars->image.img,
			&vars->image.bits_per_pixel,
			&vars->image.line_length, &vars->image.endian);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	t_vars	vars;
	void	*aux;
	int		id_line;
	int		idtypes[6];

	id_line = -1;
	if (check_args(argc, argv) != 0)
		return (1);
	init_vars(&game);
	read_map(&game, argv[1]);
	zero_array(idtypes);
	id_line = check_identifiers(&game, idtypes);
	check_map(&vars, &game, id_line);
	aux = &vars;
	init_stuff(&vars);
	vars.game = &game;
	draw_stuff(vars);
	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, (1L << 2), red_cross, aux);
	mlx_hook(vars.win, 2, (1L << 0), key_hook, aux);
	mlx_loop(vars.mlx);
	return (0);
}
