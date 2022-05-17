#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

// Display color
int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void drawPlayer(t_game *game, int a, int b)
{
	game->player.x = 300 + a;
	game->player.y = 300 + b;
	game->player.width = 8;
	game->player.height = 8;
	int color = create_trgb(0, 255, 204, 0);
	int i = game->player.y;
	int j;
	if (game->mlx_win == NULL)
		return ;
	while (i < game->player.width + game->player.y)
	{
		j = game->player.x;
		while (j < game->player.height + game->player.x)
			mlx_pixel_put(game->mlx, game->mlx_win, j++, i, color);
		++i;
	}
}

void render_background(t_game *game)
{
	int color = create_trgb(30, 30, 30, 30);
	int i = 0;
	int j;
	if (game->mlx_win == NULL)
		return ;
	while (i < 512)
	{
		j = 0;
		while (j < 1024)
			mlx_pixel_put(game->mlx, game->mlx_win, j++, i, color);
		++i;
	}
}

int main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	t_game game;

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1024, 512, "Cub3d");
	mlx_hook(game.mlx_win, 17, (1L << 2), &x_close, &game);
	render_background(&game);
	drawPlayer(&game, 0, 0);
	mlx_hook(game.mlx_win, 2, (1L << 0), &handle_keypress, &game);
	mlx_loop(game.mlx);
}