/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:48:16 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/13 19:49:19 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		***map;
	int		fd;
	int		n_lines;

	if (argc != 2)
		return (1);
	n_lines = get_line_number(argv[1]);
	if (n_lines == 0)
		return (2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (3);
	map = parse_me(fd, n_lines);
	close(fd);
	if (map == 0)
	{
		clean_map(map);
		return (0);
	}
	scale_map(map, n_lines);
	isometric_projection(map);
	mlx_operations(map);
	return (0);
}

/*
void visualize_map(int ***map)
{
	ft_printf("[\n");
	for (int i = 0; map[i]; i++)
	{
		ft_printf(" [");
		for (int j = 0; map[i][j]; j++)
		{
			ft_printf("(");
			for (int k = 0; k < 4; k++)
			{
				if (k != 3)
					ft_printf("%d, ", map[i][j][k]);
				else
					ft_printf("%d", map[i][j][k]);

			}
			ft_printf("), ");
		}
		ft_printf("]\n");
	}
	ft_printf("]\n");
}*/