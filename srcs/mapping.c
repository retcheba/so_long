/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:19:59 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/15 12:14:47 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapping(t_game *game)
{
	int		fd;
	char	*tmp;
	int		line;

	game->map = NULL;
	line = 0;
	fd = open("map", O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp)
		line++;
	while (tmp)
	{
		if (tmp)
			free(tmp);
		tmp = get_next_line(fd);
		if (tmp)
			line++;
	}
	if (tmp)
		free(tmp);
	close(fd);
	game->map = malloc((line + 1) * sizeof(char *));
	line = 0;
	fd = open("map", O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		game->map[line] = tmp;
		tmp = get_next_line(fd);
		line++;
	}
	game->map[line] = NULL;
	if (tmp)
		free(tmp);
	close(fd);
	game->win_height = line * 48;
	game->win_width = (ft_strln(game->map[0]) - 1) * 48;
}

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
			{
				mlx_put_image_to_window(game->mlx, game->win, game->chest, game->x, game->y);
				game->x_chest = game->x;
				game->y_chest = game->y;
			}
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
