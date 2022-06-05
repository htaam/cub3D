#include "cub3d.h"

int max_height(double wall_distance)
{
    int lineHeight;
    int drawStart;

    lineHeight = (int)(ScreenHeight / wall_distance);
    drawStart = -lineHeight / 2 + ScreenHeight / 2;
    if (drawStart < 0)
        return (0);
    return(drawStart); 
}

int min_height(double wall_distance)
{

    int lineHeight;
    int drawEnd;

    lineHeight = (int)(ScreenHeight / wall_distance);
    drawEnd = lineHeight / 2 + ScreenHeight / 2;
    if (drawEnd >= ScreenHeight)
        return ( ScreenHeight - 1);
    return(drawEnd); 
}

void final_draw(t_vars vars, t_draw draw, t_data image, int screen_x)
{
	int screen_y = 0;
	while (++screen_y < ScreenHeight)
	{
		if (screen_y <= (min_height(draw.perpWallDist)) && screen_y >= max_height(draw.perpWallDist))
		{
			my_mlx_pixel_put(&image, screen_x,
				screen_y, (create_trgb(100*draw.side, draw.wallX * vars.game->board[draw.mapx][draw.mapy]*50,
						100, 0)));
		}
		else if ( screen_y  > (min_height(draw.perpWallDist)))
		{
			my_mlx_pixel_put(&image, screen_x,
				screen_y, (create_trgb(0, 50,
						50, 50)));
		}
		else
		{
			my_mlx_pixel_put(&image, screen_x,
				screen_y, (create_trgb(0, 200,
						100, 100)));
		}
	}
}

void	draw_stuff(t_vars vars)
{
	double	screen_x = 0;
	t_data	image;
	t_draw	draw;
	mlx_clear_window(vars.mlx, vars.win);
	image.img = mlx_new_image(vars.mlx, ScreenWith,
			ScreenHeight);
	image.addr = mlx_get_data_addr(image.img,
			&image.bits_per_pixel,
			&image.line_length, &image.endian);

	while (++screen_x < ScreenWith)
	{
		draw.camera_x = 2 * (screen_x / ScreenWith) - 1;
		draw.ray_dir_x = vars.player.dir_x + (vars.player.plane_x * draw.camera_x);
		draw.ray_dir_y = vars.player.dir_y + (vars.player.plane_y * draw.camera_x);

		draw.mapx = (int)(vars.player.pos_x);
		draw.mapy = (int)(vars.player.pos_y);

		if (draw.ray_dir_x == 0)
			draw.deltaDistx = 1e10;
		else
			draw.deltaDistx = fabs(1 / draw.ray_dir_x);

		if (draw.ray_dir_y == 0)
			draw.deltaDisty = 1e10;
		else
			draw.deltaDisty = fabs(1 / draw.ray_dir_y);




		if(draw.ray_dir_x < 0)
		{
			draw.stepx = -1;
			draw.sideDistx = (vars.player.pos_x - draw.mapx) * draw.deltaDistx;
		}
		else
		{
			draw.stepx = 1;
			draw.sideDistx = (draw.mapx + 1 - vars.player.pos_x) * draw.deltaDistx;
		}
		if (draw.ray_dir_y < 0)
		{
			draw.stepy = -1;
			draw.sideDisty = (vars.player.pos_y - draw.mapy) * draw.deltaDisty;
		}
		else
		{
			draw.stepy = 1;
			draw.sideDisty = (draw.mapy + 1 - vars.player.pos_y) * draw.deltaDisty;
		}

		int hit = 0;
		while (hit == 0)
		{
			if (draw.sideDistx < draw.sideDisty)
			{
				draw.sideDistx += draw.deltaDistx;
				draw.mapx += draw.stepx;
				if (draw.stepx > 0)
					draw.side = 0;
				else
					draw.side = 2;
			}
			else
			{
				draw.sideDisty += draw.deltaDisty;
				draw.mapy += draw.stepy;
				if (draw.stepy > 0)
					draw.side = 1;
				else
					draw.side = 4;
			}
			if (vars.game->board[draw.mapx][draw.mapy] > '0')
				hit = 1;
		}
		
		if (draw.side == 0 || draw.side == 2)
			draw.perpWallDist = (draw.sideDistx - draw.deltaDistx);
		else
			draw.perpWallDist = (draw.sideDisty - draw.deltaDisty);
		if (draw.side == 0 || draw.side == 2)
			draw.wallX = vars.player.pos_y + draw.perpWallDist * draw.ray_dir_y;
		else
			draw.wallX = vars.player.pos_x + draw.perpWallDist * draw.ray_dir_x;
		draw.wallX -= floor(draw.wallX);

		
		final_draw(vars, draw, image, screen_x);
		
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_destroy_image(vars.mlx, image.img);
}