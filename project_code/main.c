/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:48:16 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/08 07:11:55 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void visualize_map(int ***map);

int main(int argc, char **argv)
{
	int		***map;
	int		fd;
	int		n_lines;
	
	if (argc != 2)
		return (1);
	n_lines = get_line_number(argv[1]);
	if(n_lines == 0)
	{
		ft_printf("seems to be file with empty lines or error reading the file :(\n");
		return (2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (3);
	map = parse_me(fd, n_lines);
	//visualize_map(map);
	ft_printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	mlx_operations(map);
	isometric_projection(map, 30, 45);
	
	visualize_map(map);
	//free(map);
	close(fd);
	return (0);
}


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
}