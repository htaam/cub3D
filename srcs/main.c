#include "cub3d.h"



void	init_stuff(t_vars *vars)
{
	int x_max = 1080;
	int y_max = 1080;
	
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x_max,
			y_max, "A");
	vars->image.img = mlx_new_image(vars->mlx, x_max,
			y_max);
	vars->image.addr = mlx_get_data_addr(vars->image.img,
			&vars->image.bits_per_pixel,
			&vars->image.line_length, &vars->image.endian);
}

int max_height(int wall_distance)
{
    return (1080/2 - wall_distance / 2);
}

int min_height(int wall_distance)
{
    return(wall_distance / 2 + 1080/2); 
}

int	main(int argc, char **argv)
{
	t_vars		vars;
    void		*aux;

	aux = &vars;
	init_stuff(&vars);
    (void)argv;
    (void)argc;
    int x = 0;
    int y = 0;
    int wall_distances[1080];

    int i = 0;
    while (i< 1079)
    {
        int j = 0;

        while(j++ < 100)
        {
            wall_distances[i + j] = i;
        }
        i = i + j - 1;
    }



    while (y++ < 1079)
    {
        x = 0;
        while (x++ < 1079)
        {
            if (y  <= (min_height(wall_distances[x])) && y >= max_height(wall_distances[x]))
            {
                my_mlx_pixel_put(&vars.image, x,
					y, (create_trgb(0, (50),
							255, 0)));
            }
        }
    }
    mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
 
 	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, 0L, red_cross, aux);
	mlx_hook(vars.win, 2, 0L, key_hook, aux);
	mlx_loop(vars.mlx);
 
    mlx_loop(vars.mlx);
}


