/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:57:38 by tmatias           #+#    #+#             */
/*   Updated: 2021/07/24 17:34:24 by tmatias          ###   ########.fr       */
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

# ifndef DIGITS_AND_STUFF
#  define DIGITS_AND_STUFF "-.0123456789"
# endif

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

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		image;
}				t_vars;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
int				red_cross(void);
int				mouse_hook(int mouse_code, int x, int y, t_vars *vars);
int				key_hook(int keycode, t_vars *vars);

#endif