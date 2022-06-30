/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:53:44 by retcheba          #+#    #+#             */
/*   Updated: 2022/06/30 19:43:56 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}	t_img;

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	move_player(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close(vars);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_img	planet;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 600, "so_long");
	planet.relative_path = "planet.xpm";
	planet.img = mlx_xpm_file_to_image(vars.mlx, planet.relative_path, &planet.img_width, &planet.img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, planet.img, 0, 0);
	mlx_hook(vars.win, 17, 2L<<0, close, &vars);
	mlx_key_hook(vars.win, move_player, &vars);
	mlx_loop(vars.mlx);
}
