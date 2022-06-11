/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:57:38 by tmatias           #+#    #+#             */
/*   Updated: 2022/06/11 18:44:00 by tmatias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include	<stdio.h>
# include	<unistd.h>
# include	<fcntl.h>
# include	<stdlib.h>
# include	<math.h>
# include	<mlx.h>
# include	"mlx_keys.h"
# include	"../libs/libft/src/libft.h"

# ifndef DIGITS_AND_STUFF
#  define DIGITS_AND_STUFF "-.0123456789"
# endif
# ifndef PI
#  define PI 3.1415
# endif

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define SCREENWIDTH 1080
# define SCREENHEIGHT 1080

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
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	int		side;
	double	perpwalldist;
	double	wallx;
	char	*texture[4];
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

typedef struct s_texture
{
	char	*path[4];
}				t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		**board;
	int			board_height;
	t_rgb		rgb;
	t_texture	texture;
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

//main
int		main(int argc, char *argv[]);
void	init_stuff(t_vars *vars);

// check_sargs
int		empty_line(t_game *game, int i);
int		all_idtypes(int *idtypes);
int		check_texture_extension(t_game *game, char *ext);
int		check_map_extension(char *ext);
int		check_args(int argc, char *argv[]);

//check_map
void	check_map(t_vars *vars, t_game *game, int i);
void	map_closed(t_game *game, int i, int j, int id);
void	check_map_characters(t_vars *vars, t_game *game, int i);
void	map_validity(t_game *game, int i, int j);
void	vertical_empty_line(t_game *game, int i);
int		check_around(t_game *game, int i, int j, int id);


//color
void	check_rgb(t_game *game, int i, char *s);
int		check_rgb_submit(t_game *game, int i, char *s);
void	rgb_validity(t_game *game, int i, size_t j, int c);
void	init_rgb(t_game *game, int n, char *s, int c);

//draw
int		max_height(double wall_distance);
int		min_height(double wall_distance);
void	texture(t_vars vars, t_draw draw, t_data image, int screen_x);
void	draw_stuff(t_vars vars);

//draw2
void	draw_aux1(t_draw *draw, t_vars vars);
void	draw_aux2(t_draw *draw, t_vars vars, int hit);
void	draw_aux3(t_draw *draw, t_vars vars);
void	draw_aux4(t_draw *draw, t_vars vars);
void	wall_sky(t_vars vars, int screen_x, t_data image, t_draw draw);

//hook
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int mouse_code, int x, int y, t_vars *vars);
int		red_cross(t_vars *vars);

//movement
void	forward(t_vars *vars);
void	backward(t_vars *vars);
void	right(t_vars *vars);
void	left(t_vars *vars);

//parsing
char	*get_texture_path(t_game *game, int i, char c);
int		check_textures(t_game *game, int *idtypes, int i);
int		check_identifiers(t_game *game, int *idtypes);
void	count_board_units(t_game *game, char *board);
void	read_map(t_game *game, char *board);

//player
void	get_player_pos_dir(t_vars *vars, int i, int j, char dir);
void	get_player_pos_west(t_vars *vars);
void	get_player_pos_east(t_vars *vars);
void	get_player_pos_south(t_vars *vars);

//rotate
void	rotate_player(t_vars *vars, int keycode);
void	rotate_left(t_vars *vars, double olddirx, double oldplanex);
void	rotate_right(t_vars *vars, double olddirx, double oldplanex);

//utils
void	init_vars(t_game *game);
void	print_board(t_game *game, int i);
int		*zero_array(int *array);

//aux
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//exit-free
int		free_vars(t_vars *vars);
int		exit_end(char *message);
int		free_game(t_game *game);
int		error_exit(t_game *game, char *message);
int		error_exit2(t_vars *vars, char *message);

#endif