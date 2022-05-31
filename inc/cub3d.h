/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:29:40 by mmota             #+#    #+#             */
/*   Updated: 2022/05/30 17:35:38 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx_opengl_20191021/mlx.h"
# include "../libs/libft/src/libft.h"
# include "mlx_keys.h"
# ifndef DIGITS_AND_STUFF
#  define DIGITS_AND_STUFF "-.0123456789"
# endif
# ifndef PI
#  define  PI 3.1415
# endif

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

//----------------------------------------------------------------------------
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_game
{
	t_player	player;
	void		*mlx;
	void		*mlx_win;
	char		**board;
	int			board_height;
	size_t		board_width;
}				t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		cr;
	int		cg;
	int		cb;
	int		fr;
	int		fg;
	int		fb;
}				t_data;

typedef struct s_rgb
{
	int		cr;
	int		cg;
	int		cb;
	int		fr;
	int		fg;
	int		fb;
}				t_rgb;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		image;
	t_player	player;
	t_game		*game;
	t_rgb		rgb;
}				t_vars;


//---------------------------------------------------------------------



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

////	Key_Actions
//int		handle_keypress(int key_code, t_game *game);
//void	up(t_game *game);
//void	left(t_game *game);
//void	down(t_game *game);
//void	right(t_game *game);


// Utils
//void	game_exit(t_game *game, char *message);
int		x_close(t_game *game);
void	counter_moves(t_game *game);


//Cub3d
void			drawplayer(t_game *game);
void			render_background(t_game *game);
void			init_display(t_game *game);
void			raycast(t_game *game);
int				error_exit(char *message);
int				check_args(int argc, char *argv[]);
int				check_extension (char *argv);
void			print_board(t_game *game, int i);
int				check_identifiers(t_game *game);
void			check_map(t_game *game, int i);

//Cub3d-2
void			init_stuff(t_vars *vars);
int 			max_height(double wall_distance);
int 			min_height(double wall_distance);
void			draw_stuff(t_vars vars);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
int				red_cross(void);
int				mouse_hook(int mouse_code, int x, int y, t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
void			rotate_player(t_vars *vars, int keycode);
void			forward(t_vars *vars);
void			backward(t_vars *vars);
void			right(t_vars *vars);
void			left(t_vars *vars);


#endif