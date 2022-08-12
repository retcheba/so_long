/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:42:42 by retcheba          #+#    #+#             */
/*   Updated: 2022/08/12 19:14:38 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_content_map(t_game *game)
{
	int	x;
	int	y;
	int	l;
	int	h;

	x = 0;
	y = 0;
	h = 0;
	l = 0;
	game->cmpt_heart = 0;
	game->cmpt_start = 0;
	game->cmpt_exit = 0;
	while (game->map[h])
		h++;
	while (game->map[0][l])
		l++;
	if (h < 3 || (l - 1) < 3 || h == (l - 1))
		return (1);
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1' &&
				game->map[y][x] != 'C' && game->map[y][x] != 'E' &&
				game->map[y][x] != 'P' && game->map[y][x] != '\n')
				return (1);
			if (game->map[y][x] == 'C')
				game->cmpt_heart++;
			if (game->map[y][x] == 'E')
				game->cmpt_exit++;
			if (game->map[y][x] == 'P')
				game->cmpt_start++;
			x++;
		}
		if (x != l)
			return (1);
		x = 0;
		y++;
	}
	if (game->cmpt_heart < 1 || game->cmpt_exit != 1 || game->cmpt_start != 1)
		return (1);
	return (0);
}

int	map_error2(t_game *game)
{
	if (check_content_map(game))
	{
		ft_printf("Error: wrong map\n");
		return (1);
	}
	return (0);
}
