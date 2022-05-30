#include "cub3d.h"
#define mapWidth 24
#define mapHeight 24	
#define ScreenWith 1080
#define ScreenHeight 1080
double speed = .2;
/*int worldMap2[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,6,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
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
};*/

int worldMap2[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


void	rotate_player(t_vars *vars, int keycode)
{
	double olddirx;
	double oldplanex;

	if (keycode == MLX_KEY_RIGHT)
	{
		olddirx = vars->player.dir_x;
		vars->player.dir_x = vars->player.dir_x * cos(-.1) -  vars->player.dir_y * sin(-.1);
		vars->player.dir_y = olddirx * sin(-.1) + vars->player.dir_y * cos(-.1);
		oldplanex = vars->player.plane_x;
		vars->player.plane_x = vars->player.plane_x * cos(-.1) -  vars->player.plane_y * sin(-.1);
		vars->player.plane_y = oldplanex * sin(-.1) + vars->player.plane_y * cos(-.1);
	}
	else if (keycode == MLX_KEY_LEFT)
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
	if (worldMap2[(int)(vars->player.pos_x + vars->player.dir_x * speed * 2)][(int)vars->player.pos_y] == 0)
	{
		vars->player.pos_x = vars->player.pos_x + vars->player.dir_x * speed;
	}
	if (worldMap2[(int)vars->player.pos_x][(int)(vars->player.pos_y + vars->player.dir_y * speed * 2)] == 0)
	{
		vars->player.pos_y = vars->player.pos_y + vars->player.dir_y * speed;
	}
	draw_stuff(*vars);
}

void	backward(t_vars *vars)
{
	if (worldMap2[(int)(vars->player.pos_x - vars->player.dir_x * speed * 2)][(int)vars->player.pos_y] == 0)
	{
		vars->player.pos_x = vars->player.pos_x - vars->player.dir_x * speed;
	}
	if (worldMap2[(int)vars->player.pos_x][(int)(vars->player.pos_y - vars->player.dir_y * speed * 2)] == 0)
	{
		vars->player.pos_y = vars->player.pos_y - vars->player.dir_y * speed;
	}
	draw_stuff(*vars);
}

void	right(t_vars *vars)
{
	double turnx;
	double turny;

	turnx = vars->player.dir_x * cos(PI/2) -  vars->player.dir_y * sin(PI/2);
	turny = vars->player.dir_x * sin(PI/2) + vars->player.dir_y * cos(PI/2);

	if (worldMap2[(int)(vars->player.pos_x - turnx * speed * 2)][(int)vars->player.pos_y] == 0)
	{
		vars->player.pos_x = vars->player.pos_x - turnx * speed;
	}
	if (worldMap2[(int)vars->player.pos_x][(int)(vars->player.pos_y - turny * speed * 2)] == 0)
	{
		vars->player.pos_y = vars->player.pos_y - turny * speed;
	}
	draw_stuff(*vars);
}


void	left(t_vars *vars)
{
	double turnx;
	double turny;

	turnx = vars->player.dir_x * cos(-PI/2) -  vars->player.dir_y * sin(-PI/2);
	turny = vars->player.dir_x * sin(-PI/2) + vars->player.dir_y * cos(-PI/2);

	if (worldMap2[(int)(vars->player.pos_x - turnx * speed * 2)][(int)vars->player.pos_y] == 0)
	{
		vars->player.pos_x = vars->player.pos_x - turnx * speed;
	}
	if (worldMap2[(int)vars->player.pos_x][(int)(vars->player.pos_y - turny * speed * 2)] == 0)
	{
		vars->player.pos_y = vars->player.pos_y - turny * speed;
	}
	draw_stuff(*vars);
}


/* w = 13	a = 0	d = 2	s = 1	<- =  123	-> = 124*/
