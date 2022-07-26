/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:59:04 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/26 19:06:08 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(t_game *game)
{
	if (game->map[game->y / 48][(game->x + 48) / 48] == '0'
			|| game->map[game->y / 48][(game->x + 48) / 48] == 'C'
			|| game->map[game->y / 48][(game->x + 48) / 48] == 'P'
			|| (game->map[game->y / 48][(game->x + 48) / 48] == 'E'
			&& game->cmpt_heart == 0))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass,
			game->x, game->y);
		game->x += 48;
		mlx_put_image_to_window(game->mlx, game->win, game->link_right,
			game->x, game->y);
		game->cmpt_moves++;
		ft_printf("move n°%d\n", game->cmpt_moves);
		ft_is_collectible(game);
		ft_is_win(game);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->link_right,
			game->x, game->y);
}

void	ft_left(t_game *game)
{
	if (game->map[(game->y) / 48][(game->x - 48) / 48] == '0'
			|| game->map[game->y / 48][(game->x - 48) / 48] == 'C'
			|| game->map[game->y / 48][(game->x - 48) / 48] == 'P'
			|| (game->map[game->y / 48][(game->x - 48) / 48] == 'E'
			&& game->cmpt_heart == 0))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass,
			game->x, game->y);
		game->x -= 48;
		mlx_put_image_to_window(game->mlx, game->win, game->link_left,
			game->x, game->y);
		game->cmpt_moves++;
		ft_printf("move n°%d\n", game->cmpt_moves);
		ft_is_collectible(game);
		ft_is_win(game);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->link_left,
			game->x, game->y);
}

void	ft_top(t_game *game)
{
	if (game->map[(game->y - 48) / 48][game->x / 48] == '0'
			|| game->map[(game->y - 48) / 48][game->x / 48] == 'C'
			|| game->map[(game->y - 48) / 48][game->x / 48] == 'P'
			|| (game->map[(game->y - 48) / 48][game->x / 48] == 'E'
			&& game->cmpt_heart == 0))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass,
			game->x, game->y);
		game->y -= 48;
		mlx_put_image_to_window(game->mlx, game->win, game->link_back,
			game->x, game->y);
		game->cmpt_moves++;
		ft_printf("move n°%d\n", game->cmpt_moves);
		ft_is_collectible(game);
		ft_is_win(game);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->link_back,
			game->x, game->y);
}

void	ft_bottom(t_game *game)
{
	if (game->map[(game->y + 48) / 48][game->x / 48] == '0'
			|| game->map[(game->y + 48) / 48][game->x / 48] == 'C'
			|| game->map[(game->y + 48) / 48][game->x / 48] == 'P'
			|| (game->map[(game->y + 48) / 48][game->x / 48] == 'E'
			&& game->cmpt_heart == 0))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass,
			game->x, game->y);
		game->y += 48;
		mlx_put_image_to_window(game->mlx, game->win, game->link,
			game->x, game->y);
		game->cmpt_moves++;
		ft_printf("move n°%d\n", game->cmpt_moves);
		ft_is_collectible(game);
		ft_is_win(game);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, game->link,
			game->x, game->y);
}
