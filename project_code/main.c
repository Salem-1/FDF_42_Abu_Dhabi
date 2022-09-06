/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:48:16 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/14 13:08:04 by ahsalem          ###   ########.fr       */
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
#incldue <stdio.h>
void visualize_map(int ***map)
{
	printf("[\n");
	for (int i = 0; map[i]; i++)
	{
		printf(" [");
		for (int j = 0; map[i][j]; j++)
		{
			printf("(");
			for (int k = 0; k < 4; k++)
			{
				if (k != 3)
					printf("%d, ", map[i][j][k]);
				else
					printf("%d", map[i][j][k]);

			}
			printf("), ");
		}
		printf("]\n");
	}
	printf("]\n");
}*/