/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:43:27 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/26 18:56:00 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close(game);
	if (keycode == RIGHT || keycode == D)
		ft_right(game);
	if (keycode == LEFT || keycode == Q)
		ft_left(game);
	if (keycode == TOP || keycode == Z)
		ft_top(game);
	if (keycode == BOTTOM || keycode == S)
		ft_bottom(game);
	return (0);
}

void	ft_is_win(t_game *game)
{
	if (game->map[game->y / 48][game->x / 48] == 'E' && game->cmpt_heart == 0)
	{
		ft_printf("You win !\n");
		ft_close(game);
	}
}

void	ft_is_collectible(t_game *game)
{
	if (game->map[game->y / 48][game->x / 48] == 'C')
	{
		game->cmpt_heart--;
		game->map[game->y / 48][game->x / 48] = '0';
		if (game->cmpt_heart == 0)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->chest_or,
				game->x_chest, game->y_chest);
		}
	}
}
