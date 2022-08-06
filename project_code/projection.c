/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:06:53 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/06 19:42:06 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void isometric_projection(int ***map, int i, int j)
{
	
	while (map[++i])
	{
		while (map[i][++j])
		{
			convert_3D_to_2D(map[i][j]);
		}
		j = -1;
	}
    //return (map);
}

void convert_3D_to_2D(int *coordinate)
{
	int	k;

	k = -1;
	while (++k < 4)
	{
		if (k != 2)
			coordinate[k]++;
		else
		coordinate[k] = 0;
	}
	
}