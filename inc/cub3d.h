/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmota <mmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:29:40 by mmota             #+#    #+#             */
/*   Updated: 2022/05/16 16:29:02 by mmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include "../libs/minilibx-linux/mlx.h"
//# include "../libs/minilibx_opengl_20191021/mlx.h"
# include "../libs/libft/src/libft.h"
# include "mlx_keys.h"

typedef struct s_player
{
	int	x;
	int	y;
	int width;
	int height;
	int	direct;
	int	count;
}				t_player;

typedef struct s_game
{
	t_player	player;
	void		*mlx;
	void		*mlx_win;
	char		**board;
	int			board_width;
	int			board_height;
}				t_game;

//	so_long
void	init_game(t_game *game);
void	init_vars(t_game *game);
void	init_img(t_game *game);

// Check Board
void	count_board_units(t_game *game, char *board);
void	check_board_form(t_game *game, char *line, size_t len);
int		board_close(t_game *game);
int		board_elements(t_game *game);

// Board
void	init_board(t_game *game);
void	read_board(t_game *game, char *board);
void	draw_background(t_game *game);
void	init_player(t_game *game, int y, int x);
void	draw_board(t_game *game);

//	Key_Actions
int		handle_keypress(int key_code, t_game *game);
void	up(t_game *game);
void	left(t_game *game);
void	down(t_game *game);
void	right(t_game *game);


// Utils
//void	game_exit(t_game *game, char *message);
int		x_close(t_game *game);
void	counter_moves(t_game *game);


//Cub3d
void drawPlayer(t_game *game, int a, int b);

#endif