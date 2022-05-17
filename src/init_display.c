#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

void	init_display(t_game *game)
{
	// Initial position coordinates
	game->player.posX = 22; 
	game->player.posY = 12; 
	//// Initial direction vectors 
	//double dirX = -1; 
	//double dirY = 0;
	//// 2d raycaster "camera plane"
	//double planeX = 0;
	//double planeY = 0.66;
//
	//// time of current time
	//double time = 0;
	//// time of previous frame
	//double oldtime = 0; 

	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, screenWidth, screenHeight, "Cub3d");
}
