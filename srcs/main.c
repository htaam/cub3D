#include "cub3d.h"
#define mapWidth 24
#define mapHeight 24
#define ScreenWith 1080
#define ScreenHeight 1080

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};






void	init_stuff(t_vars *vars)
{
	int x_max = ScreenHeight;
	int y_max = ScreenWith;
	
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x_max,
			y_max, "A");
	vars->image.img = mlx_new_image(vars->mlx, x_max,
			y_max);
	vars->image.addr = mlx_get_data_addr(vars->image.img,
			&vars->image.bits_per_pixel,
			&vars->image.line_length, &vars->image.endian);
}

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


void	draw_stuff(t_vars vars)
{
	double screen_x = 1;
	t_data image;

	mlx_clear_window(vars.mlx, vars.win);
	image.img = mlx_new_image(vars.mlx, ScreenWith,
			ScreenHeight);
	image.addr = mlx_get_data_addr(image.img,
			&image.bits_per_pixel,
			&image.line_length, &image.endian);

	while (screen_x < ScreenWith)
	{
		double	camera_x = 2 * screen_x/ScreenWith;
		double	ray_dir_x = vars.player.dir_x + vars.player.plane_x * camera_x;
		double	ray_dir_y = vars.player.dir_y + vars.player.plane_y * camera_x;

		int mapx = (int)(vars.player.pos_x);
		int mapy = (int)(vars.player.pos_y);

		double sideDistx;
		double sideDisty;
		double deltaDistx;
		double deltaDisty;
		if (ray_dir_x == 0)
			deltaDistx = 1e10;
		else
			deltaDistx = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			deltaDisty = 1e10;
		else
			deltaDisty = fabs(1 / ray_dir_y);
		int stepx;
		int stepy;

		int hit = 0;
		int side;

		if(ray_dir_x < 0)
		{
			stepx = -1;
			sideDistx = (vars.player.pos_x - mapx) * deltaDistx;
		}
		else
		{
			stepx = 1;
			sideDistx = (mapx + 1 - vars.player.pos_x) * deltaDistx;
		}
		if (ray_dir_y < 0)
		{
			stepy = -1;
			sideDisty = (vars.player.pos_y - mapy) * deltaDisty;
		}
		else
		{
			stepx = 1;
			sideDisty = (mapy + 1 - vars.player.pos_y) * deltaDisty;
		}
		while (hit == 0)
		{
			if (sideDistx < sideDisty)
			{
				sideDistx += deltaDistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sideDisty += deltaDisty;
				mapy += stepy;
				side = 1;
			}
			if (worldMap[mapx][mapy] > 0)
				hit = 1;
		}
		double perpWallDist;
		

		if (side == 0)
			perpWallDist = (sideDistx - deltaDistx);
		else
			perpWallDist = (sideDisty - deltaDisty);
		
		int screen_y = 1;
		while (screen_y < ScreenHeight)
		{
			if (screen_y <= (min_height(perpWallDist)) && screen_y >= max_height(perpWallDist))
			{
				my_mlx_pixel_put(&image, screen_x,
					screen_y, (create_trgb(100*side, 0,
							100, 200*side)));
			}
			else if ( screen_y  > (min_height(perpWallDist)))
			{
				my_mlx_pixel_put(&image, screen_x,
					screen_y, (create_trgb(0, 50,
							50, 50)));
			}
			else
			{
				my_mlx_pixel_put(&image, screen_x,
					screen_y, (create_trgb(0, 200,
							100, 0)));
			}
			screen_y++;
		}
		screen_x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_destroy_image(vars.mlx, image.img);
}


int	main(int argc, char **argv)
{
	t_vars		vars;
    void		*aux;

	aux = &vars;
	init_stuff(&vars);
	(void)argv;
	(void)argc;
	vars.player.pos_x = 2.5;
	vars.player.pos_y = 2.5;
	vars.player.dir_x = 0;
	vars.player.dir_y = 1;
	vars.player.plane_x = -.66;
	vars.player.plane_y = 0;
	draw_stuff(vars);
	
 
 	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, 0L, red_cross, aux);
	mlx_hook(vars.win, 2, 0L, key_hook, aux);
	mlx_loop(vars.mlx);
 
    mlx_loop(vars.mlx);		
}
