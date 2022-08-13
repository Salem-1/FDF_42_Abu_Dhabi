

#include "fdf.h"


int	scale_ratio(n_lines)
{
	if(n_lines < 35)
		return (40);
	else if(n_lines < 70)
		return (10);
	else if(n_lines < 120)
		return (7);
	else if (n_lines < 210)
		return (4);
	else 
		return (2);
}
/*
handling the outliar maps that has small n_lines with large z, that was causing segfautl.
*/
void scale_map(int ***map,int n_lines)
{
	int	i;
	int	k;
	int	scaler;
	int check_z;


	i = -1;
	k = -1;
	scaler = 0;
	check_z = 0;
	while (++i < 1)
	{
		while (map[i][++k] != NULL)
		{
			check_z += abs(map[i][k][2]);
		}
		k  = -1;
	}
	i = -1;
	check_z /= n_lines;
	if (check_z > 25)
		scaler = 8;
	else
		scaler = scale_ratio(n_lines);
	while (++i < n_lines)
	{
		while (map[i][++k] != NULL)
		{
			map[i][k][0] *= scaler;
			map[i][k][1] *= scaler;
			map[i][k][2] *= scaler ;
		}
		k  = -1;
	}

}