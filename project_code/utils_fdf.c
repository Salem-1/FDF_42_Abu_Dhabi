

#include "fdf.h"


int	scale_ratio(n_lines)
{
	if(n_lines < 35)
		return (35);
	else if(n_lines < 70)
		return (10);
	else if(n_lines <= 150)
		return (5);
	else if (n_lines < 201)
		return (2);
	else 
		return (1);
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
	int	tmp;

	tmp = 0;
	i = -1;
	k = -1;
	scaler = 0;
	check_z = 0;
	while (++i < n_lines)
	{
		while (map[i][++k] != NULL && n_lines <= 60)
			check_z += abs(map[i][k][2]);
		k  = -1;
		check_z /= n_lines;
		if(check_z > tmp)
			tmp = check_z;
		else	
			check_z = tmp;	
	//ft_printf("check_z = %d, n_lines = %d\n",check_z, n_lines );
		if (check_z > 20)
			scaler = 9;
		else if (check_z >= 10)
			scaler = 13;
		else if (check_z >= 6)
			scaler = 15;
		else
			scaler = scale_ratio(n_lines);
	}
	i = -1;
	ft_printf("scaler = %d, check_z = %d\n", scaler, check_z);
	while (++i < n_lines)
	{
		while (map[i][++k] != NULL)
		{
			map[i][k][0] *= scaler;
			map[i][k][1] *= scaler;
			map[i][k][2] *= scaler;
		}
		k  = -1;
	}

}