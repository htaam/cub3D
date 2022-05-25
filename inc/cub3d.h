/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:29:40 by mmota             #+#    #+#             */
/*   Updated: 2022/05/25 19:12:49 by marmota          ###   ########.fr       */
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

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

typedef struct s_player
{
	//// Initial player position
	int	posX;
	int	posY;
	//// Initial direction vectors 
	double dirX; 
	double dirY;
	//// 2d raycaster "camera plane"
	double planeX;
	double planeY;
	int width;
	int height;
	int	direct;
	int	count;
}				t_player;

//typedef struct s_cub
//{
//	
//
//}			t_cub;

typedef struct s_game
{
	t_player	player;
	void		*mlx;
	void		*mlx_win;
	char		**board;
	int			board_height;
	size_t		board_width;
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
void	read_map(t_game *game, char *board);
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
void	drawPlayer(t_game *game);
void	render_background(t_game *game);
void	init_display(t_game *game);
void	raycast(t_game *game);
int		error_exit(char *message);
int		check_args(int argc, char *argv[]);
int		check_extension (char *argv);
void	print_board(t_game *game, int i);
int		check_identifiers(t_game *game);
void	map_isclosed(t_game *game, int i);


#endif