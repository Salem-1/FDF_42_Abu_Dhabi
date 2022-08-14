/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:48:12 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/13 20:22:52 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	***parse_me(int fd, int n_lines)
{
	int	***map;
	int	i;

	i = -1;
	map = malloc(sizeof(int **) * (n_lines + 1));
	if (!map)
		return (NULL);
	while (++i < n_lines)
	{
		if (!fill_map(fd, map, i))
			return (0);
	}
	map[i] = NULL;
	return (map);
}

int	fill_map(int fd, int ***map, int i)
{
	char	*one_line;
	char	**split_result;
	int		split_count;
	int		counter[3];

	counter[0] = i;
	counter[1] = -1;
	counter[2] = -1;
	one_line = get_next_line(fd);
	if (one_line == NULL)
		return (0);
	split_result = ft_split(one_line, ' ');
	split_count = splitted_counter(split_result);
	map[counter[0]] = malloc(sizeof(int *) * (split_count + 1));
	if (map[counter[0]] == NULL)
		return (0);
	while (split_result[++counter[1]] != NULL)
	{
		counter[2] = fill_map_helper(map, (int *)counter, split_result);
		if (counter[2] == -2)
			return (0);
	}
	map[counter[0]][counter[2]] = NULL;
	free_split(split_result);
	return (1);
}

int	fill_map_helper(int ***map, int *counter, char **split_result)
{
	char	**splitted_split_result;
	int		i;
	int		j;
	int		k;

	i = counter[0];
	j = counter[1];
	k = counter[2];
	splitted_split_result = NULL;
	map[i][++k] = malloc(sizeof(int) * 4);
	if (map[i][k] == NULL)
		return (-2);
	splitted_split_result = ft_split(split_result[j], ',');
	map[i][k][0] = k;
	map[i][k][1] = i;
	map[i][k][2] = -1 * ft_atoi(splitted_split_result[0]);
	map[i][k][3] = ft_atox(splitted_split_result[1]);
	free_split(splitted_split_result);
	return (k);
}

int	get_line_number(char *file_name)
{
	char	*line;
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
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}	
	if (close(fd) == -1)
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
