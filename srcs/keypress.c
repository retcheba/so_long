/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:43:27 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/22 17:43:29 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close(game);
	if (keycode == RIGHT || keycode == D)
	{
		if (game->map[game->y / 48][(game->x + 48) / 48] == '0'
				|| game->map[game->y / 48][(game->x + 48) / 48] == 'C'
				|| game->map[game->y / 48][(game->x + 48) / 48] == 'P'
				|| (game->map[game->y / 48][(game->x + 48) / 48] == 'E' && game->cmpt_heart == 0))
		{
			mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			game->x += 48;
			mlx_put_image_to_window(game->mlx, game->win, game->link_right, game->x, game->y);
			game->cmpt_moves++;
			ft_printf("move n°%d\n", game->cmpt_moves);
			if (game->map[game->y / 48][game->x / 48] == 'C')
			{
				game->cmpt_heart--;
				game->map[game->y / 48][game->x / 48] = '0';
				if (game->cmpt_heart == 0)
					mlx_put_image_to_window(game->mlx, game->win, game->chest_or, game->x_chest, game->y_chest);
			}
			if (game->map[game->y / 48][game->x / 48] == 'E' && game->cmpt_heart == 0)
			{
				ft_printf("You win !\n");
				ft_close(game);
			}
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->link_right, game->x, game->y);
	}
	if (keycode == LEFT || keycode == Q)
	{
		if (game->map[(game->y) / 48][(game->x - 48) / 48] == '0'
				|| game->map[game->y / 48][(game->x - 48) / 48] == 'C'
				|| game->map[game->y / 48][(game->x - 48) / 48] == 'P'
				|| (game->map[game->y / 48][(game->x - 48) / 48] == 'E' && game->cmpt_heart == 0))
		{
			mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			game->x -= 48;
			mlx_put_image_to_window(game->mlx, game->win, game->link_left, game->x, game->y);
			game->cmpt_moves++;
			ft_printf("move n°%d\n", game->cmpt_moves);
			if (game->map[game->y / 48][game->x / 48] == 'C')
			{
				game->cmpt_heart--;
				game->map[game->y / 48][game->x / 48] = '0';
				if (game->cmpt_heart == 0)
					mlx_put_image_to_window(game->mlx, game->win, game->chest_or, game->x_chest, game->y_chest);
			}
			if (game->map[game->y / 48][game->x / 48] == 'E' && game->cmpt_heart == 0)
			{
				ft_printf("You win !\n");
				ft_close(game);
			}
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->link_left, game->x, game->y);
	}
	if (keycode == TOP || keycode == Z)
	{
		if (game->map[(game->y - 48) / 48][game->x / 48] == '0'
				|| game->map[(game->y - 48) / 48][game->x / 48] == 'C'
				|| game->map[(game->y - 48) / 48][game->x / 48] == 'P'
				|| (game->map[(game->y - 48) / 48][game->x / 48] == 'E' && game->cmpt_heart == 0))
		{
			mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			game->y -= 48;
			mlx_put_image_to_window(game->mlx, game->win, game->link_back, game->x, game->y);
			game->cmpt_moves++;
			ft_printf("move n°%d\n", game->cmpt_moves);
			if (game->map[game->y / 48][game->x / 48] == 'C')
			{
				game->cmpt_heart--;
				game->map[game->y / 48][game->x / 48] = '0';
				if (game->cmpt_heart == 0)
					mlx_put_image_to_window(game->mlx, game->win, game->chest_or, game->x_chest, game->y_chest);
			}
			if (game->map[game->y / 48][game->x / 48] == 'E' && game->cmpt_heart == 0)
			{
				ft_printf("You win !\n");
				ft_close(game);
			}
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->link_back, game->x, game->y);
	}
	if (keycode == BOTTOM || keycode == S)
	{
		if (game->map[(game->y + 48) / 48][game->x / 48] == '0'
				|| game->map[(game->y + 48) / 48][game->x / 48] == 'C'
				|| game->map[(game->y + 48) / 48][game->x / 48] == 'P'
				|| (game->map[(game->y + 48) / 48][game->x / 48] == 'E' && game->cmpt_heart == 0))
		{
			mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
			game->y += 48;
			mlx_put_image_to_window(game->mlx, game->win, game->link, game->x, game->y);
			game->cmpt_moves++;
			ft_printf("move n°%d\n", game->cmpt_moves);
			if (game->map[game->y / 48][game->x / 48] == 'C')
			{
				game->cmpt_heart--;
				game->map[game->y / 48][game->x / 48] = '0';
				if (game->cmpt_heart == 0)
					mlx_put_image_to_window(game->mlx, game->win, game->chest_or, game->x_chest, game->y_chest);
			}
			if (game->map[game->y / 48][game->x / 48] == 'E' && game->cmpt_heart == 0)
			{
				ft_printf("You win !\n");
				ft_close(game);
			}
		}
		else
			mlx_put_image_to_window(game->mlx, game->win, game->link, game->x, game->y);
	}
	return (0);
}
