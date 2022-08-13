/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:06:53 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/12 20:15:11 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//redo the matrix multiplication on the Z axis
//Ask google.

/*
	possible angels:
	 5 5 -50 3 5
	 5 5 -60 10 3
	 5 5 -50 -45 -5
	 5 5 -50 -45 -2
	 5 5 -60 -45 -2
	  5 5 -60 20 -2
	  5 5 -60 -5 -2
	  5 5 -50 -35 -15  best till now like the sample fdf
	  5 5 -50 -35 -15
	  a b g    c  d
*/

void	isometric_projection(int ***map)
{
	int	i;
	int	j;
	int	ax;
	float angels[5];
	
	//a = 10 
	//b = 10
	i = -1;
	j = -1;
	angels[0] = 5 * M_PI / 180 ;
	angels[1] =  5* M_PI / 180;
	angels[2] = -50 * M_PI / 180;
	angels[3] = -35 * M_PI / 180;
	angels[4]= -15 * M_PI / 180;
	while (map[++i])
	{
		while (map[i][++j])
		{
			rotateX3D(angels[2], &map[i][j]);
			rotateY3D(angels[3], &map[i][j]); 
			rotateZ3D(angels[4], &map[i][j]);
			ax = map[i][j][0];
	
			map[i][j][0] = ((cos(angels[0]) * (ax)) + (sin(angels[1]) * map[i][j][2])) ;
			map[i][j][1] = ((sin(angels[0]) * sin(angels[1]) * (ax)) + (cos(angels[0]) * map[i][j][1]) + (sin(angels[0]) * cos(angels[1]) * map[i][j][2])) ;
			map[i][j][2] = 0;
			
		}
		j = -1;
	}
}

void rotateX3D(float theta, int **node) 
{
   	float sinTheta = sin(theta);
   	float cosTheta = cos(theta);
    int y = node[0][1];
    int z = node[0][2];
    node[0][1] = y * cosTheta - z * sinTheta;
    node[0][2] = z * cosTheta + y * sinTheta;
   
}

void rotateY3D(float theta, int **node) 
{
   	float sinTheta = sin(theta);
   	float cosTheta = cos(theta);
    int x = node[0][0];
    int z = node[0][2];
    node[0][0] = x * cosTheta + z * sinTheta;
    node[0][2] = z * cosTheta - x * sinTheta;

}

void rotateZ3D(float theta, int **node) 
{
   	float	sinTheta = sin(theta);
   	float	cosTheta = cos(theta);
    int		x = node[0][0];
    int y = node[0][1];
    node[0][0] = x * cosTheta - y * sinTheta;
    node[0][1] = y * cosTheta + x * sinTheta;
   
}

		/*
			map[i][j][0]= ax * cos(a) - map[i][j][1] * sin(a);
			map[i][j][1] = map[i][j][1] *cos(a) - ax * sin(a);
*/
			//isometrix projection equation from wikipedia
			

/*
			ax = map[i][j][0];
			map[i][j][0] = (cos(a) * (ax)) + (sin(b) * map[i][j][2]) ;
			map[i][j][1] = (sin(a) * sin(b) * (ax)) + (cos(a) * map[i][j][1]) + (sin(a) * cos(b) * map[i][j][2]);
			map[i][j][2] = 0;
	
			map[i][j][0] = (cos(a) *ax) + (sin(a) * z); 
			map[i][j][1] = (cos(a) * map[i][j][1])  + (map[i][j][2] * ((-1) * sin(a)));
			map[i][j][2] = 0;
			
			// rotation around x or y axis, I don't remember actually
			map[i][j][0] = ax; 
			map[i][j][1] = (cos(a) * map[i][j][1])  + (map[i][j][1] * ((-1) * sin(a)));
			map[i][j][2] = 0;
			*/




			//rotation around x_axis only
			/*
			// Multiplying row pitch and yow together
			map[i][j][0] = (cos(a) * cos(b) * (ax)) + (((cos(a) * sin(b) * sin(g)) - (sin(a) * cos(g))) *  map[i][j][1]) + (((cos(a) * sin(b) * cos(g)) + (sin(a) * sin(g))) * map[i][j][2]) ;
			map[i][j][1] = (sin(a) * cos(b) * (ax)) + (((sin(a)* sin(b)  * sin(g)) + (cos(a) * cos(g))) * map[i][j][1]) + (((sin(a) * sin(b) * cos(g)) - (cos(a) * sin(g))) * map[i][j][2]) ;
			map[i][j][2] = 0;
			*/
			/*map[i][j][0] *=  sin(a);
			map[i][j][1] *=  sin(a);
			map[i][j][2] = 0;
			*/		
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
			ax = map[i][j][0];
			map[i][j][0] = (cos(a) * (ax)) + (sin(b) * map[i][j][2]) ;
			map[i][j][1] = (sin(a) * sin(b) * (ax)) + (cos(a) * map[i][j][1]) + (sin(a) * cos(b) * map[i][j][2]);
			map[i][j][2] = 0;
Isometric projection equation refrence ;
https://en.wikipedia.org/wiki/Isometric_projection
*/

/*
old non acurate projection from wikipedia
ax = &map[i][j][0];
			map[i][j][0] = (cos(a) * (*ax)) + (sin(b) * map[i][j][2]) ;
			map[i][j][1] = (sin(a) * sin(b) * (*ax)) + (cos(a) * map[i][j][1]) + (sin(a) * cos(b) * map[i][j][2]);
			map[i][j][2] = 0;
			
		Search for matrix rotation
*/