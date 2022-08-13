/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:42:42 by retcheba          #+#    #+#             */
/*   Updated: 2022/08/13 11:35:54 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_content_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->h = 0;
	game->l = 0;
	game->cmpt_heart = 0;
	game->cmpt_start = 0;
	game->cmpt_exit = 0;
	while (game->map[game->h])
		game->h++;
	while (game->map[0][game->l])
		game->l++;
	if (game->h < 3 || (game->l - 1) < 3 || game->h == (game->l - 1))
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
		if (x != game->l)
			return (1);
		x = 0;
		y++;
	}
	if (game->cmpt_heart < 1 || game->cmpt_exit != 1 || game->cmpt_start != 1)
		return (1);
	return (0);
}

static int	check_wall_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->l)
	{
		if (game->map[0][x] != '1')
			return (1);
		if (game->map[game->h][x] != '1')
			return (1);
		x++;
	}
	y = 0;
	while (y < game->h)
	{
		if (game->map[y][0] != '1')
			return (1);
		if (game->map[y][game->l] != '1')
			return (1);
		y++;
	}
	if (game->map[game->h][game->l] != '1')
		return (1);
	return (0);
}

int	map_error2(t_game *game)
{
	int	r;

	if (check_content_map(game))
	{
		r = write(2, "Error\n", 6);
		r = write(2, "wrong map\n", 10);
		return (1);
	}
	game->h--;
	game->l -= 2;
	if (check_wall_map(game))
	{
		r = write(2, "Error\n", 6);
		r = write(2, "wrong map\n", 10);
		return (1);
	}
	(void)r;
	return (0);
}
