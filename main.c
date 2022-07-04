/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:53:44 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/04 17:27:47 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 541, 524, "so_long");
	game.img = mlx_xpm_file_to_image(game.mlx, "planet.xpm", &game.img_width, &game.img_height);
	mlx_key_hook(game.win, keypress, &game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
	mlx_loop(game.mlx);
}
