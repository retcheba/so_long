/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 22:19:59 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/26 16:25:02 by retcheba         ###   ########.fr       */
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
