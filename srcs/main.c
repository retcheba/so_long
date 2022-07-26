/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:53:44 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/26 15:54:31 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;

	ft_mapping(&game);
	game.mlx = mlx_init();
	ft_init_images(&game);
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height,
			"so_long");
	game.cmpt_moves = 0;
	mlx_key_hook(game.win, ft_keypress, &game);
	mlx_hook(game.win, 17, 1, ft_close, &game);
	ft_put_image(&game);
	mlx_loop(game.mlx);
}

void	ft_init_images(t_game *game)
{
	game->chest = mlx_xpm_file_to_image(game->mlx, "sprites/chest.xpm",
			&game->img_width, &game->img_height);
	game->chest_or = mlx_xpm_file_to_image(game->mlx, "sprites/chest_or.xpm",
			&game->img_width, &game->img_height);
	game->heart = mlx_xpm_file_to_image(game->mlx, "sprites/heart.xpm",
			&game->img_width, &game->img_height);
	game->tree = mlx_xpm_file_to_image(game->mlx, "sprites/tree.xpm",
			&game->img_width, &game->img_height);
	game->grass = mlx_xpm_file_to_image(game->mlx, "sprites/grass.xpm",
			&game->img_width, &game->img_height);
	game->link = mlx_xpm_file_to_image(game->mlx, "sprites/link.xpm",
			&game->img_width, &game->img_height);
	game->link_back = mlx_xpm_file_to_image(game->mlx,
			"sprites/link_back.xpm", &game->img_width, &game->img_height);
	game->link_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/link_left.xpm", &game->img_width, &game->img_height);
	game->link_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/link_right.xpm", &game->img_width, &game->img_height);
}

int	ft_close(t_game *game)
{
	int	i;

	mlx_destroy_image(game->mlx, game->chest);
	mlx_destroy_image(game->mlx, game->chest_or);
	mlx_destroy_image(game->mlx, game->heart);
	mlx_destroy_image(game->mlx, game->tree);
	mlx_destroy_image(game->mlx, game->link);
	mlx_destroy_image(game->mlx, game->link_back);
	mlx_destroy_image(game->mlx, game->link_left);
	mlx_destroy_image(game->mlx, game->link_right);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(0);
	return (0);
}
