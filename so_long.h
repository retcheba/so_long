/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:38 by retcheba          #+#    #+#             */
/*   Updated: 2022/07/04 12:17:33 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
}	t_game;

void	put_image(t_game *game);
int	close(t_game *game);
int	keypress(int keycode, t_game *game);

#endif
