/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 08:35:08 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/14 08:52:27 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_map(int ***map, int n_lines)
{
	int	i;
	int	scaler;
	int	check_z;
	int	tmp;
	int	k;

	check_z = 0;
	i = -1;
	tmp = 0;
	k = -1;
	scaler = get_scaler(map, n_lines, check_z, tmp);
	while (++i < n_lines)
	{
		while (map[i][++k] != NULL)
		{
			map[i][k][0] *= scaler;
			map[i][k][1] *= scaler;
			map[i][k][2] *= scaler;
		}
		k = -1;
	}
}

int	scale_ratio(int n_lines, int flag, int check_z)
{
	if (flag == 0)
	{
		if (n_lines < 35)
			return (35);
		else if (n_lines < 70)
			return (10);
		else if (n_lines <= 150)
			return (5);
		else if (n_lines < 201)
			return (2);
		else
			return (1);
	}
	else
	{
		if (check_z > 20)
			return (9);
		else if (check_z >= 10)
			return (13);
		else if (check_z >= 6)
			return (15);
		else
			return (scale_ratio(n_lines, 0, 0));
	}
}

int	get_scaler(int ***map, int n_lines, int check_z, int tmp)
{
	int	i;
	int	k;
	int	scaler;

	i = -1;
	k = -1;
	while (++i < n_lines)
	{
		while (map[i][++k] != NULL && n_lines <= 60)
			check_z += abs(map[i][k][2]);
		k = -1;
		check_z /= n_lines;
		if (check_z > tmp)
			tmp = check_z;
		else
			check_z = tmp;
		scaler = scale_ratio(n_lines, 1, check_z);
	}
	return (scaler);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
	}
	free(split);
}

void	clean_map(int ***map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
			free(map[i][j]);
		free(map[i]);
		j = -1;
	}
	free(map[i]);
}
