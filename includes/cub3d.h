/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmota <marmota@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:57:38 by tmatias           #+#    #+#             */
/*   Updated: 2022/06/08 17:15:07 by marmota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "mlx_keys.h"
# include "../libs/libft/src/libft.h"

# ifndef DIGITS_AND_STUFF
#  define DIGITS_AND_STUFF "-.0123456789"
# endif
# ifndef PI
#  define  PI 3.1415
# endif

#define mapWidth 24
#define mapHeight 24
#define ScreenWith 1080
#define ScreenHeight 1080

typedef struct s_img
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*data;
}			t_img;

typedef struct s_draw
{
	double	screen_x;
	double	screen_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		mapx;
	int		mapy;
	double	sideDistx;
	double	sideDisty;
	double	deltaDistx;
	double	deltaDisty;
	int		stepx;
	int		stepy;
	int		side;
	double	perpWallDist;
	double	wallX;
	char 	*texture[4];
}				t_draw;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_rgb
{
	int		cr;
	int		cg;
	int		cb;
	int		fr;
	int		fg;
	int		fb;
}				t_rgb;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		**board;
	int			board_height;
	size_t		board_width;
	t_rgb		rgb;
}				t_game;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		image;
	t_player	player;
	t_game		*game;
	t_img		*img;
}				t_vars;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
int				red_cross(void);
int				mouse_hook(int mouse_code, int x, int y, t_vars *vars);
int				key_hook(int keycode, t_vars *vars);
void			rotate_player(t_vars *vars, int keycode);
void			draw_stuff(t_vars vars);
void			forward(t_vars *vars);
void			backward(t_vars *vars);
void			right(t_vars *vars);
void			left(t_vars *vars);
//--------------------------------------------------
int				error_exit(char *message);
int				check_extension(char *ext);
int				check_args(int argc, char *argv[]);
void			check_map(t_vars *vars, t_game *game, int i);
int				check_identifiers(t_game *game, int *idtypes);
void			check_rgb(t_game *game, int i, char *s);
int				x_close(t_game *game);
void			init_vars(t_game *game);
//Parsing
int				all_idtypes(int *idtypes);
void			read_map(t_game *game, char *board);
//Utils
int				*zero_array(int *array);

t_img			init_textures(t_vars *vars);


#endif