#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

void	down(t_game *game)
{
	++game->player.y;
	drawPlayer(game, 0, 5);
}

void	right(t_game *game)
{
	++game->player.x;
	drawPlayer(game, 5, 0);
}

void	up(t_game *game)
{
	--game->player.y;
	drawPlayer(game, 0, -5);
}

void	left(t_game *game)
{
	--game->player.x;
	drawPlayer(game, -5, 0);
}

int	handle_keypress(int key_code, t_game *game)
{
	if (key_code == MLX_KEY_ESC)
		x_close(game);
	if (key_code == MLX_KEY_S || key_code == MLX_KEY_DOWN)
		down(game);
	if (key_code == MLX_KEY_D || key_code == MLX_KEY_RIGHT)
		right(game);
	if (key_code == MLX_KEY_W || key_code == MLX_KEY_UP)
		up(game);
	if (key_code == MLX_KEY_A || key_code == MLX_KEY_LEFT)
		left(game);
	return (key_code);
}