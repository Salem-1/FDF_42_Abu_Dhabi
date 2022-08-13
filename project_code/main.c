/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:48:16 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/13 17:46:47 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <time.h>
#include <stdio.h>

void visualize_map(int ***map);

int main(int argc, char **argv)
{
	int		***map;
	int		fd;
	int		n_lines;
	
	 clock_t t;
    t = clock();
   
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
 
   // printf("fun() took %f seconds to execute \n", time_taken);
    
	argc++;
	// if (argc != 2)
	// 	return (1);
	t = clock();
	n_lines = get_line_number(argv[1]);
	t = clock() - t;
	ft_printf("lines = %d ,",n_lines);
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("get_line_num took %f seconds to execute \n", time_taken);
	
	if(n_lines == 0)
	{
		ft_printf("seems to be file with empty lines or error reading the file :(\n");
		return (2);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (3);
	//ft_printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	t = clock();
	map = parse_me(fd, n_lines);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("parse took %f seconds to execute \n", time_taken);
	t = clock();
	scale_map(map, n_lines);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("scale_me took %f seconds to execute \n", time_taken);
	//visualize_map(map);
	//int id = fork();
	//if (id == 0)
	///{
		t = clock();
	isometric_projection(map);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
	printf("isometric took %f seconds to execute \n", time_taken);
		//return (0);
		//visualize_map(map);
	mlx_operations(map);
//	}
	// else
	// {
	// 	isometric_projection(map, -145,30, 42);
	// 	mlx_operations(map);
	// 	return (0);
	// }
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