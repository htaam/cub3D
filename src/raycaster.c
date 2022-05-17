#include "cub3d.h"
#include "stdio.h"
#include "stdlib.h"

// Display color
int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void drawPlayer(t_game *game)
{
	game->player.width = 8;
	game->player.height = 8;
	int color = create_trgb(0, 255, 204, 0);
	int i = game->player.posY;
	int j;
	if (game->mlx_win == NULL)
		return ;
	while (i < game->player.width + game->player.posY)
	{
		j = game->player.posX;
		while (j < game->player.height + game->player.posX)
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
		{
			mlx_pixel_put(game->mlx, game->mlx_win, j++, i, color);	
		}
		++i;
	}
}

int main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		return (0);
	init_vars(&game);
	read_map(&game, argv[1]);
	init_display(&game);
	mlx_hook(game.mlx_win, 17, (1L << 2), &x_close, &game);
	render_background(&game);
	drawPlayer(&game);
	mlx_hook(game.mlx_win, 2, (1L << 0), &handle_keypress, &game);
	mlx_loop(game.mlx);
}