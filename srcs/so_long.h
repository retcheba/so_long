/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:38 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/15 12:14:24 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# define Z 122
# define S 115
# define Q 113
# define D 100
# define TOP 65362
# define BOTTOM 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_game
{
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
	int		cmpt_heart;
}	t_game;

char	*get_next_line(int fd);
void	mapping(t_game *game);
void	ft_put_image(t_game *game);
int	ft_close(t_game *game);
int	keypress(int keycode, t_game *game);
int	ft_strln(char *s);

#endif
