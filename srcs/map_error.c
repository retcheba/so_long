/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retcheba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:03:21 by retcheba          #+#    #+#             */
/*   Updated: 2022/08/12 18:49:27 by retcheba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ber(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] == 'r')
	{
		if (argv[1][i - 2] == 'e')
		{
			if (argv[1][i - 3] == 'b')
			{
				if (argv[1][i - 4] == '.')
					return (0);
			}
		}
	}
	return (1);
}

int	map_error(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || check_ber(argv))
	{
		ft_printf("Error: missing map name argument or wrong map name\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: missing map name argument or wrong map name\n");
		return (1);
	}
	close(fd);
	return (0);
}
