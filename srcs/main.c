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
    int lineHeight;
    int drawStart;

    lineHeight = 1080 / wall_distance;
    drawStart = -lineHeight / 2 + 1080 / 2;
    if (drawStart < 0)
        return (0);
    return(drawStart); 
}

int min_height(int wall_distance)
{

    int lineHeight;
    int drawEnd;

    lineHeight = 1080 / wall_distance;
    drawEnd = lineHeight / 2 + 1080 / 2;
    if (drawEnd >= 1080)
        return ( 1080 - 1);
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
}


