#include "cub3d.h"


void	init_stuff(t_vars *vars)
{
	int x_max = 1920;
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

    while (x++ < 1079)
    {
        y = 0;
        while (y++ < 1079)
        {
            my_mlx_pixel_put(&vars.image, x,
					y, (create_trgb(0, 2.5 * (x*y) + 50,
							2.5 * (x/y), 0.3 * (x%y + 2))));
        }
    }
    mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
 
 	mlx_hook(vars.win, 4, 0L, mouse_hook, aux);
	mlx_hook(vars.win, 17, 0L, red_cross, aux);
	mlx_hook(vars.win, 2, 0L, key_hook, aux);
	mlx_loop(vars.mlx);
 
    mlx_loop(vars.mlx);
}


