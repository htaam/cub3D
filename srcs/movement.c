#include "cub3d.h"
#define mapWidth 24
#define mapHeight 24
#define ScreenWith 1080
#define ScreenHeight 1080
int worldMap2[mapWidth][mapHeight]=
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


void	rotate_player(t_vars *vars, int keycode)
{
	double olddirx;
	double oldplanex;

	if (keycode == 123)
	{
		olddirx = vars->player.dir_x;
		vars->player.dir_x = vars->player.dir_x * cos(-.1) -  vars->player.dir_y * sin(-.1);
		vars->player.dir_y = olddirx * sin(-.1) + vars->player.dir_y * cos(-.1);
		oldplanex = vars->player.plane_x;
		vars->player.plane_x = vars->player.plane_x * cos(-.1) -  vars->player.plane_y * sin(-.1);
		vars->player.plane_y = oldplanex * sin(-.1) + vars->player.plane_y * cos(-.1);
	}
	else if (keycode == 124)
	{
		olddirx = vars->player.dir_x;
		vars->player.dir_x = vars->player.dir_x * cos(.1) -  vars->player.dir_y * sin(.1);
		vars->player.dir_y = olddirx * sin(.1) + vars->player.dir_y * cos(.1);
		oldplanex = vars->player.plane_x;
		vars->player.plane_x = vars->player.plane_x * cos(.1) -  vars->player.plane_y * sin(.1);
		vars->player.plane_y = oldplanex * sin(.1) + vars->player.plane_y * cos(.1);
	}
	draw_stuff(*vars);
}

void	forward(t_vars *vars)
{
	if (worldMap2[(int)(vars->player.pos_x + vars->player.dir_x * .1)][(int)vars->player.pos_y] == 0)
		vars->player.pos_x = vars->player.pos_x + vars->player.dir_x * .1;
	if (worldMap2[(int)vars->player.pos_x][(int)(vars->player.dir_y + vars->player.dir_y * .1)] == 0)
		vars->player.pos_y = vars->player.pos_y + vars->player.dir_y * .1;
	draw_stuff(*vars);
}


/* w = 13	a = 0	d = 2	s = 1	<- =  123	-> = 124*/
