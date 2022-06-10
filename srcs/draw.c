#include "cub3d.h"

int	max_height(double wall_distance)
{
	int	line_height;
	int	draw_start;

	line_height = (int)(ScreenHeight / wall_distance);
	draw_start = -line_height / 2 + ScreenHeight / 2;
	return (draw_start);
}

int	min_height(double wall_distance)
{
	int	line_height;
	int	draw_end;

	line_height = (int)(ScreenHeight / wall_distance);
	draw_end = line_height / 2 + ScreenHeight / 2;
	return (draw_end);
}

void	texture(t_vars vars, t_draw draw, t_data image, int screen_x)
{
	t_img	no;
	double	wally;

	draw.screen_y = 0;
	no.img = mlx_xpm_file_to_image(vars.mlx, vars.game->texture.path[draw.side],
			&no.img_width, &no.img_height);
	no.data = (int *)mlx_get_data_addr(no.img, &no.bits_per_pixel,
			&no.line_length, &no.endian);
	while (++draw.screen_y < ScreenHeight)
	{
		if (draw.screen_y < (min_height(draw.perpWallDist)) && draw.screen_y
			> max_height(draw.perpWallDist))
		{
			wally = (double)(draw.screen_y - max_height(draw.perpWallDist))
				/ (double)(min_height(draw.perpWallDist)
					- max_height(draw.perpWallDist));
			my_mlx_pixel_put(&image, screen_x, draw.screen_y,
				(no.data[(((int)(no.img_height * wally)))
					* (no.line_length / 4) + ((int)(no.img_width
							* draw.wallX)) * ((no.bits_per_pixel / 4) / 8)]));
		}
		else
			wall_sky(vars, screen_x, image, draw);
	}
}

void	draw_stuff(t_vars vars)
{
	double	screen_x;
	t_data	image;
	t_draw	draw;
	int		hit;

	screen_x = 0;
	hit = 0;
	mlx_clear_window(vars.mlx, vars.win);
	image.img = mlx_new_image(vars.mlx, ScreenWith,
			ScreenHeight);
	image.addr = mlx_get_data_addr(image.img,
			&image.bits_per_pixel,
			&image.line_length, &image.endian);
	while (++screen_x < ScreenWith)
	{
		draw.camera_x = 2 * (screen_x / ScreenWith) - 1;
		draw_aux4(&draw, vars);
		draw_aux3(&draw, vars);
		draw_aux2(&draw, vars, hit);
		draw_aux1(&draw, vars);
		texture(vars, draw, image, screen_x);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_destroy_image(vars.mlx, image.img);
}
