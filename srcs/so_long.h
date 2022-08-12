/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:38 by retcheba          #+#    #+#             */
/*   Updated: 2022/08/12 16:48:11 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# define W 119
# define S 115
# define A 97
# define D 100
# define TOP 65362
# define BOTTOM 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_game
{
	char	*map_name;
	char	**map;
	void	*mlx;
	void	*win;
	void	*link;
	void	*link_back;
	void	*link_left;
	void	*link_right;
	void	*grass;
	void	*tree;
	void	*heart;
	void	*chest;
	void	*chest_or;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		x_chest;
	int		y_chest;
	int		x_link;
	int		y_link;
	int		cmpt_heart;
	int		cmpt_moves;
}	t_game;

void	ft_init_images(t_game *game);
void	ft_mapping(t_game *game);
int		ft_line_map(t_game *game);
void	ft_put_image(t_game *game);
void	ft_what_image(t_game *game, int y, int x);
void	ft_what_image2(t_game *game, int y, int x);
int		ft_keypress(int keycode, t_game *game);
void	ft_right(t_game *game);
void	ft_left(t_game *game);
void	ft_top(t_game *game);
void	ft_bottom(t_game *game);
void	ft_is_collectible(t_game *game);
void	ft_is_win(t_game *game);
int		ft_strln(char *s);
int		ft_close(t_game *game);

#endif
