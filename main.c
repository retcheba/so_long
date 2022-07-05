/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:53:44 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/05 18:32:24 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close(game);
	if (keycode == 100 || keycode == 65363)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		game->x += 48;
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->x, game->y);
	}
	if (keycode == 113 || keycode == 65361)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		game->x -= 48;
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->x, game->y);
	}
	if (keycode == 122 || keycode == 65362)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		game->y -= 48;
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->x, game->y);
	}
	if (keycode == 115 || keycode == 65364)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		game->y += 48;
		mlx_put_image_to_window(game->mlx, game->win, game->player, game->x, game->y);
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1152, 720, "so_long");
	game.grass = mlx_xpm_file_to_image(game.mlx, "sprites/grass.xpm", &game.img_width, &game.img_height);
	game.player = mlx_xpm_file_to_image(game.mlx, "sprites/player.xpm", &game.img_width, &game.img_height);
	mlx_key_hook(game.win, keypress, &game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	game.x = 0;
	game.y = 0;
	mlx_put_image_to_window(game.mlx, game.win, game.player, game.x, game.y);
	mlx_loop(game.mlx);
}
