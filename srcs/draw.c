#include "cub3d.h"

int max_height(double wall_distance)
{
    int lineHeight;
    int drawStart;

    lineHeight = (int)(ScreenHeight / wall_distance);
    drawStart = -lineHeight / 2 + ScreenHeight / 2;
    return(drawStart); 
}

int min_height(double wall_distance)
{

    int lineHeight;
    int drawEnd;

    lineHeight = (int)(ScreenHeight / wall_distance);
    drawEnd = lineHeight / 2 + ScreenHeight / 2;
    return(drawEnd); 
}

void	texture(t_vars vars, t_draw draw, t_data image, int screen_x)
{
	t_img NO;
	double	wallY;

	NO.img = mlx_xpm_file_to_image(vars.mlx, vars.game->texture.path[draw.side], &NO.img_width, &NO.img_height);
	NO.data = (int *)mlx_get_data_addr(NO.img, &NO.bits_per_pixel, &NO.line_length, &NO.endian);
	int screen_y = 0;
	while (++screen_y < ScreenHeight)
	{
		if (screen_y < (min_height(draw.perpWallDist)) && screen_y > max_height(draw.perpWallDist))
		{
			double wall_size = (double)(min_height(draw.perpWallDist) - max_height(draw.perpWallDist));
			wallY=(double)(screen_y - max_height(draw.perpWallDist))/wall_size;
			
			my_mlx_pixel_put(&image, screen_x, screen_y,
				(NO.data[ (((int)(NO.img_height * wallY))) * (NO.line_length / 4) +
					 ((int)(NO.img_width * draw.wallX)) * ((NO.bits_per_pixel / 4) / 8)]));
		}
		else if ( screen_y  >= (min_height(draw.perpWallDist)))
		{
			my_mlx_pixel_put(&image, screen_x, screen_y, (create_trgb(0, vars.game->rgb.fr,
						vars.game->rgb.fg, vars.game->rgb.fb)));
		}
		else
		{
			my_mlx_pixel_put(&image, screen_x, screen_y, (create_trgb(0, vars.game->rgb.cr,
						vars.game->rgb.cg ,vars.game->rgb.cb)));
		}
	}
}

void	draw_stuff(t_vars vars)
{
	double	screen_x;
	t_data	image;
	t_draw	draw;
	int	hit;

	screen_x = 0;
	hit = 0;
	mlx_clear_window(vars.mlx, vars.win);
	image.img = mlx_new_image(vars.mlx, ScreenWith,
			ScreenHeight);
	image.addr = mlx_get_data_addr(image.img,
			&image.bits_per_pixel,
			&image.line_length, &image.endian);
	init_textures(&vars);
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