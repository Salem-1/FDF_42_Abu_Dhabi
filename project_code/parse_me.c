/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:48:12 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/06 19:31:26 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ***parse_me(int fd, int n_lines)
{
	char	*one_line;
	int		***map;
	int		i;
	char 	**split_result;
	int		j;
	char	**splitted_split_result;
	int		k;
	int		split_count;

	k = -1;
	j = -1;
	i  = -1;
	map  = malloc(sizeof(int **) * (n_lines + 1));
	if (!map)
		return (NULL);
	
	while (++i < n_lines)
	{
		one_line = get_next_line(fd);
		if (one_line == NULL)
		{
			ft_printf("end of file shouldn't reach this point, inside pars_me() n_lines = %d \n", n_lines);
			return (NULL);
		}
		split_result = ft_split(one_line, ' ');
		split_count =  splitted_counter(split_result );
		//allocating for one full line data inside map[i]
		map[i] = malloc(sizeof(int *) * (split_count + 1));
		if (map[i] == NULL)
			return (NULL);
		while (split_result[++j] != NULL)
		{
			map[i][++k] =  malloc(sizeof(int) * 4);
				// if (map[i][j] == NULL)
				// 	return (NULL);
			splitted_split_result = ft_split(split_result[j], ',');
			//ft_printf("splitted result = %d\n", ft_atoi(splitted_split_result[0]));
			map[i][k][0] = k;
			map[i][k][1] = i;
			map[i][k][2] = ft_atoi(splitted_split_result[0]),  //z_axis which is the value
			//ft_printf("%s ", splitted_split_result[1]);
			map[i][k][3] =  255; //ft_atox(splitted_split_result[1])the split rsult I will set it for 255 the defualt white for now split(split_result[0][++j], ',')[1]
			free(splitted_split_result);
		}
		map[i][k] = NULL;
		k  = -1;
		free(split_result);
		j = -1;
	}
	map[i] = NULL;
	return (map);
}
	

int get_line_number(char *file_name)
{
	char *line;
	int		fd;
	int		i;

	i = 0;
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Bad file \n");
		return (0);
	}
	line = get_next_line(fd);
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}	
	if(close(fd) == -1)
		return (0);
	return (i);
}

int	splitted_counter(char **split_result)
{
	int	i;

	i = -1;
	while (split_result[++i])
		;
	return (i);
}

	// //ft_printf("number of lines = %d\n", n_lines);
	// 	one_line = get_next_line(fd);
	// 	split_result = ft_split(one_line, ' ');
	// while (++i < n_lines)
	// {
	// 	if (one_line == NULL)
	// 		break;
	// 	while (split_result[0][++j] != NULL)
	// 	{
	// 		map[i] = &split_result[0];
	// 	}
	// 	free(split_result);
	// 	j = -1
	// 	free(one_line);
	// }
	// map[i + 1] = NULL;