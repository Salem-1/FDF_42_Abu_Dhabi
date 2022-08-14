/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:06:53 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/14 08:05:37 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(int ***m)
{
	int		i;
	int		j;
	int		ax;
	float	d[5];

	i = -1;
	j = -1;
	d[0] = 5 * M_PI / 180 ;
	d[1] = 5 * M_PI / 180;
	d[2] = -50 * M_PI / 180;
	d[3] = -35 * M_PI / 180;
	d[4] = -15 * M_PI / 180;
	while (m[++i])
	{
		while (m[i][++j])
		{
			rotate_matrix(m, i, j, (float *)d);
			ax = m[i][j][0];
			m[i][j][0] = ((cos(d[0]) * (ax)) + (sin(d[1]) * m[i][j][2]));
			m[i][j][1] = sin(d[0]) * sin(d[1]) * (ax) + cos(d[0]) * m[i][j][1];
			m[i][j][1] += sin(d[0]) * cos(d[1]) * m[i][j][2];
			m[i][j][2] = 0;
		}
		j = -1;
	}
}

void	rotate_matrix(int ***map, int i, int j, float *angels)
{
	rotate_x(angels[2], &map[i][j]);
	rotate_y(angels[3], &map[i][j]);
	rotate_z(angels[4], &map[i][j]);
}

void	rotate_x(float theta, int **node)
{
	float	sintheta;
	float	costheta;
	int		z;
	int		y;

	costheta = cos(theta);
	sintheta = sin(theta);
	y = node[0][1];
	z = node[0][2];
	node[0][1] = y * costheta - z * sintheta;
	node[0][2] = z * costheta + y * sintheta;
}

void	rotate_y(float theta, int **node)
{
	float	sintheta;
	float	costheta;
	int		x;
	int		z;

	sintheta = sin(theta);
	costheta = cos(theta);
	x = node[0][0];
	z = node[0][2];
	node[0][0] = x * costheta + z * sintheta;
	node[0][2] = z * costheta - x * sintheta;
}

void	rotate_z(float theta, int **node)
{
	float	sintheta;
	float	costheta;
	int		x;
	int		y;

	sintheta = sin(theta);
	costheta = cos(theta);
	x = node[0][0];
	y = node[0][1];
	node[0][0] = x * costheta - y * sintheta;
	node[0][1] = y * costheta + x * sintheta;
}
/*
Refrences;
*/
//Isometric projection: https://en.wikipedia.org/wiki/Isometric_projection;
//Rotation Matrecies: https://www.khanacademy.org/rotating-3d-shapes

/*
	possible angels:
	  5 5 -50 -35 -15  best till now like the sample fdf
	  5 5 -50 -35 -15
	  a b g    c  d
*/

/* angels d = {angle_x, angel_y, _angel_z, angel_alpha, angel_beta}*/

/*
	m = map; but norminette don't like long lines
*/