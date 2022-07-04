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

void	put_image(t_game *game)
{
	game->img = mlx_xpm_file_to_image(game->mlx, "planet.xpm", &game->img_width, &game->img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 10, 10);
}

int	close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == 53)
		close(game);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 600, 600, "so_long");
	put_image(&game);
	mlx_hook(game.win, 17, 1L<<17, close, &game);
	mlx_key_hook(game.win, keypress, &game);
	mlx_loop(game.mlx);
}
