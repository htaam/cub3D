/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:43:43 by marmota           #+#    #+#             */
/*   Updated: 2022/06/11 14:37:23 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_end(char *message)
{
	printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

int	error_exit(t_game *game, char *message)
{
	(void)game;
	printf("Error\n%s\n", message);
	//free_game(game);
	exit(EXIT_FAILURE);
}

int	error_exit2(t_vars *vars, char *message)
{
	(void) vars;
	printf("Error\n%s\n", message);
	//free_vars(vars);
	exit(EXIT_FAILURE);
}

int	free_game(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->board_height)
		if (game->board && game->board[i])
			free(game->board[i]);
	if (game->texture.path)
		free(game->texture.path);
	if (game->board)
		free(game->board);
	return (0);
}

int free_vars(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < vars->game->board_height)
		if (vars->game->board && vars->game->board[i])
			free(vars->game->board[i]);
	if (vars->game->board)
		free(vars->game->board);
	if (vars->win)
		free(vars->win);
	if (vars->mlx)
		free(vars->mlx);
	return(0);
}