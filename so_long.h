/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:38 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/08 18:25:20 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_game
{
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
	void	*chest_open;
	void	*chest_or;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
}	t_game;

int	ft_close(t_game *game);
int	keypress(int keycode, t_game *game);

#endif
