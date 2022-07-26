/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:25:34 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/26 16:31:00 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_game *game)
{
	int	x;
	int	y;

	game->y = 0;
	game->x = 0;
	y = 0;
	x = 0;
	game->cmpt_heart = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			ft_what_image(game, y, x);
			ft_what_image2(game, y, x);
			game->x += 48;
			x++;
		}
		game->x = 0;
		game->y += 48;
		x = 0;
		y++;
	}
	game->x = game->x_link;
	game->y = game->y_link;
}

void	ft_what_image(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass,
			game->x, game->y);
	}
	if (game->map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tree,
			game->x, game->y);
	}
	if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->heart,
			game->x, game->y);
		game->cmpt_heart++;
	}
}

void	ft_what_image2(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->chest,
			game->x, game->y);
		game->x_chest = game->x;
		game->y_chest = game->y;
	}
	if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->link,
			game->x, game->y);
		game->x_link = game->x;
		game->y_link = game->y;
	}
}
