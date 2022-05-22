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

int	main(int argc, char **argv)
{
	t_vars		vars;
    void		*aux;

	aux = &vars;
	init_stuff(&vars);
	(void)argv;
	(void)argc;
	t_player player;
	player.pos_x = 15;
	player.pos_y = 20;
	player.dir_x = -1;
	player.dir_y = -1;
	player.plane_x = 0;
	player.plane_y = 0.66;
	double screen_x = 1;
	while (screen_x < ScreenWith)
	{
		double	camera_x = 2 * screen_x/ScreenWith;
		double	ray_dir_x = player.dir_x + player.plane_x * camera_x;
		double	ray_dir_y = player.dir_y + player.plane_y * camera_x;

		int mapx = (int)(player.pos_x);
		int mapy = (int)(player.pos_y);

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
			sideDistx = (player.pos_x - mapx) * deltaDistx;
		}
		else
		{
			stepx = 1;
			sideDistx = (mapx + 1 - player.pos_x) * deltaDistx;
		}
		if (ray_dir_y < 0)
		{
			stepy = -1;
			sideDisty = (player.pos_y - mapy) * deltaDisty;
		}
		else
		{
			stepx = 1;
			sideDisty = (mapy + 1 - player.pos_y) * deltaDisty;
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
				my_mlx_pixel_put(&vars.image, screen_x,
					screen_y, (create_trgb(50*side, 0,
							100, 0)));
			}
			else if ( screen_y  > (min_height(perpWallDist)))
			{
				my_mlx_pixel_put(&vars.image, screen_x,
					screen_y, (create_trgb(0, 100,
							0, 0)));
			}
			else
			{
				my_mlx_pixel_put(&vars.image, screen_x,
					screen_y, (create_trgb(0, 0,
							0, 100)));
			}
			screen_y++;
		}
		screen_x++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
 
 	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, 0L, red_cross, aux);
	mlx_hook(vars.win, 2, 0L, key_hook, aux);
	mlx_loop(vars.mlx);
 
    mlx_loop(vars.mlx);		
}




/*int	main(int argc, char **argv)
{
	t_vars		vars;
    void		*aux;

	aux = &vars;
	init_stuff(&vars);
    (void)argv;
    (void)argc;
    int x = 0;
    int y = -1;
    int wall_distances[1080];
    int wall_sides[1080];

    int i = 0;
    int p = 0;
    while (i < 1080)
    {  
        if (i % 100 == 0)
            p++;
        wall_distances[i] = p ;
        wall_sides[i] = 1 ;
        //printf("%d\t", wall_distances[i]);
        i++;
    }



    while (++y < 1080)
    {
        x = 0;
        //printf("y = %d\n" ,y);
        while (x < 1080)
        {
          //  printf("x = %d\t" ,x);
            if (y  <= (min_height(wall_distances[x])) && y >= max_height(wall_distances[x]))
            {
                my_mlx_pixel_put(&vars.image, x,
					y, (create_trgb(0, (50),
							100 / wall_sides[x - 1], 0)));
            }
            else if ( y  > (min_height(wall_distances[x])))
            {
                my_mlx_pixel_put(&vars.image, x,
					y, (create_trgb(0, (50),
							0, 0)));
            }
            else
            {
                my_mlx_pixel_put(&vars.image, x,
					y, (create_trgb(0, (50),
							0, 200)));
            }
            x++;
        }
    }

    mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
 
 	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, 0L, red_cross, aux);
	mlx_hook(vars.win, 2, 0L, key_hook, aux);
	mlx_loop(vars.mlx);
 
    mlx_loop(vars.mlx);
}*/


