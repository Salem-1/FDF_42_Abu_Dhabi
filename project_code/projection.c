/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:06:53 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/07 19:40:48 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//redo the matrix multiplication on the Z axis
//Ask google.
void	isometric_projection(int ***map, float a, float b)
{
	int	i;
	int	j;
	int	*ax;
	int	scale_factor;

	scale_factor = 1000;
	i = -1;
	j = -1;
	a = a * M_1_PI / 180 ;
	b= b * M_1_PI / 180;
	while (map[++i])
	{
		while (map[i][++j])
		{
			ax = &map[i][j][0];
			map[i][j][0] = (cos(a) * (*ax)) + (sin(b) * map[i][j][2]) * scale_factor ;
			map[i][j][1] = (sin(a) * sin(b) * (*ax)) + (cos(a) * map[i][j][1]) + (sin(a) * cos(b) * map[i][j][2]) * scale_factor;
			map[i][j][2] = 0;
		}
		j = -1;
	}
}
	// alpha = alpha_degree * M_PI / 180;
	// beta = beta_degree * M_1_PI /180;
//hardcode everything :(


// A  =[
// 	[1,       0,         0     ], 
// 	[0,  cos(alpha), sin(alpha)]
// 	[0, -sin(alpha), cos(alpha)]
// ]
// A[0][] = {1, 0, 0};
// B
// [
// 	[cos(beta), 0, -sin(beta)], 
// 	[    0,     1,      0    ],
// 	[sin(beta), 0,  cos(beta)]
// ]
// /*
// converting angle to radian , a = 30
// a = a * pi/180
// */
/*
Isometric projection equation refrence ;
https://en.wikipedia.org/wiki/Isometric_projection
*/