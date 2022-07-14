/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:53:44 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/14 23:47:38 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_game *game)
{
	int	x;
	int	y;
	int	x_link;
	int	y_link;
	
	y_link = 0;
	x_link = 0;
	game->y = 0;
	game->x = 0;
	y = 0;
	x = 0;
	game->cmpt_heart = 0;
	while (game->map[y])
	{
		
		while (game->map[y][x])
		{
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tree, game->x, game->y);
			if (game->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->heart, game->x, game->y);
				game->cmpt_heart++;;
			}
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->chest, game->x, game->y);
			if (game->map[y][x] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->link, game->x, game->y);
				x_link = game->x;
				y_link = game->y;
			}
			game->x += 48;
			x++;
		}
		game->x = 0;
		game->y += 48;
		x = 0;
		y++;
	}
	game->x = x_link;
	game->y = y_link;
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

int	keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close(game);
	if (keycode == RIGHT || keycode == D)
	{
		if (game->map[(game->y) / 48][(game->x + 48) / 48] == '0' || game->map[(game->y) / 48][(game->x + 48) / 48] == 'C'
				|| game->map[(game->y) / 48][(game->x + 48) / 48] == 'P')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			game->x += 48;
			mlx_put_image_to_window(game->mlx, game->win, game->link_right, game->x, game->y);
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->link_right, game->x, game->y);
	}
	if (keycode == LEFT || keycode == Q)
	{
		if (game->map[(game->y) / 48][(game->x - 48) / 48] == '0' || game->map[(game->y) / 48][(game->x - 48) / 48] == 'C'
				|| game->map[(game->y) / 48][(game->x - 48) / 48] == 'P')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			game->x -= 48;
			mlx_put_image_to_window(game->mlx, game->win, game->link_left, game->x, game->y);
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->link_left, game->x, game->y);
	}
	if (keycode == TOP || keycode == Z)
	{
		if (game->map[(game->y - 48) / 48][game->x / 48] == '0' || game->map[(game->y - 48) / 48][game->x / 48] == 'C'
				|| game->map[(game->y - 48) / 48][game->x / 48] == 'P')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			game->y -= 48;
			mlx_put_image_to_window(game->mlx, game->win, game->link_back, game->x, game->y);
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->link_back, game->x, game->y);
	}
	if (keycode == BOTTOM || keycode == S)
	{
		if (game->map[(game->y + 48) / 48][game->x / 48] == '0' || game->map[(game->y + 48) / 48][game->x / 48] == 'C'
				|| game->map[(game->y + 48) / 48][game->x / 48] == 'P')
		{
			mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			game->y += 48;
			mlx_put_image_to_window(game->mlx, game->win, game->link, game->x, game->y);
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->link, game->x, game->y);
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	mapping(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height, "so_long");
	game.chest = mlx_xpm_file_to_image(game.mlx, "sprites/chest.xpm", &game.img_width, &game.img_height);
	game.chest_or = mlx_xpm_file_to_image(game.mlx, "sprites/chest_or.xpm", &game.img_width, &game.img_height);
	game.heart = mlx_xpm_file_to_image(game.mlx, "sprites/heart.xpm", &game.img_width, &game.img_height);
	game.tree = mlx_xpm_file_to_image(game.mlx, "sprites/tree.xpm", &game.img_width, &game.img_height);
	game.grass = mlx_xpm_file_to_image(game.mlx, "sprites/grass.xpm", &game.img_width, &game.img_height);
	game.link = mlx_xpm_file_to_image(game.mlx, "sprites/link.xpm", &game.img_width, &game.img_height);
	game.link_back = mlx_xpm_file_to_image(game.mlx, "sprites/link_back.xpm", &game.img_width, &game.img_height);
	game.link_left = mlx_xpm_file_to_image(game.mlx, "sprites/link_left.xpm", &game.img_width, &game.img_height);
	game.link_right = mlx_xpm_file_to_image(game.mlx, "sprites/link_right.xpm", &game.img_width, &game.img_height);
	mlx_key_hook(game.win, keypress, &game);
	mlx_hook(game.win, 17, 1, ft_close, &game);
	ft_put_image(&game);
	mlx_loop(game.mlx);
}
