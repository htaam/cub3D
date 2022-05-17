#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

void	init_display(t_game *game)
{
	// Initial position coordinates
	game->player.posX = 22; 
	game->player.posY = 12; 
	//// Initial direction vectors 
	game->player.dirX = -1; 
	game->player.dirY = 0;
	//// 2d raycaster "camera plane"
	game->player.planeX = 0;
	game->player.planeY = 0.66;
//
	//// time of current time
	//double time = 0;
	//// time of previous frame
	//double oldtime = 0; 

	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, screenWidth, screenHeight, "Cub3d");
}
