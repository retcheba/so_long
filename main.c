/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:53:44 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/14 22:14:34 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapping(t_game *game)
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
	printf("win_width = %d\n", game->win_width);
	printf("win_height = %d\n", game->win_height);
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
	if (keycode == 100 || keycode == 65363)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		game->x += 48;
		mlx_put_image_to_window(game->mlx, game->win, game->link_right, game->x, game->y);
	}
	if (keycode == 113 || keycode == 65361)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		game->x -= 48;
		mlx_put_image_to_window(game->mlx, game->win, game->link_left, game->x, game->y);
	}
	if (keycode == 122 || keycode == 65362)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		game->y -= 48;
		mlx_put_image_to_window(game->mlx, game->win, game->link_back, game->x, game->y);
	}
	if (keycode == 115 || keycode == 65364)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->grass, game->x, game->y);
		game->y += 48;
		mlx_put_image_to_window(game->mlx, game->win, game->link, game->x, game->y);
	}
	return (0);
}

int	main(void)
{
	t_game	game;
	int		l;

	mapping(&game);
	l = 0;
	while (game.map[l])
	{
		printf("%s", game.map[l]);
		l++;
	}
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
	game.y = 0;
	game.x = 0;
	while (game.x < 1152)
	{
		while (game.y < 720)
		{
			mlx_put_image_to_window(game.mlx, game.win, game.grass, game.x, game.y);
			game.y += 48;
		}
		game.y = 0;
		game.x += 48;
	}
	game.y = 0;
	game.x = 0;
	while (game.x < 1152)
	{
		mlx_put_image_to_window(game.mlx, game.win, game.tree, game.x, game.y);
		game.x += 48;
	}
	game.y = 0;
	game.x = 0;
	while (game.y < 720)
	{
		mlx_put_image_to_window(game.mlx, game.win, game.tree, game.x, game.y);
		game.y += 48;
	}
	game.y = 720 - 48;
	game.x = 0;
	while (game.x < 1152)
	{
		mlx_put_image_to_window(game.mlx, game.win, game.tree, game.x, game.y);
		game.x += 48;
	}
	game.y = 0;
	game.x = 1152 - 48;
	while (game.y < 720)
	{
		mlx_put_image_to_window(game.mlx, game.win, game.tree, game.x, game.y);
		game.y += 48;
	}
	game.x = 48 * 11;
	game.y = 48 * 7;
	mlx_put_image_to_window(game.mlx, game.win, game.chest, game.x, game.y);
	game.x = 48 * 12;
	game.y = 48 * 7;
	mlx_put_image_to_window(game.mlx, game.win, game.chest_or, game.x, game.y);
	game.x = 48 * 2;
	game.y = 48;
	mlx_put_image_to_window(game.mlx, game.win, game.heart, game.x, game.y);
	game.x = 48;
	game.y = 48;
	mlx_put_image_to_window(game.mlx, game.win, game.link, game.x, game.y);
	mlx_loop(game.mlx);
}
