#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

// Calculate ray position and direction
void raycast(t_game *game)
{
	int x;
	int w;
	double cameraX;
	double rayDirX;
	double rayDirY;
	x = 0;
	w = 0;
	while (x < w)
	{
		cameraX = 2 * x / (double)w - 1;
		rayDirX = game->player.dirX + game->player.planeX * cameraX;
		rayDirY = game->player.dirY + game->player.planeY * cameraX;
		++x;
	}
	printf("%f, %f\n", rayDirX, rayDirY );
}

