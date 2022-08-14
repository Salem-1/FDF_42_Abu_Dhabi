

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

void free_split(char **split)
{
	int	i;

	i = -1;
	while(split[++i])
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

int	ft_atox(char *n)
{
	int	len;
	int	result;

	if (n == NULL)
		return (0x00ffffff);
	len = 0;
	result = 0;
	if (*n == '0')
	{
		n++;
		if (*n == 'x')
			n++;
	}
	else
		return (0);
	len = ft_strlen(n);
	while (*(n))
	{
		*n = ft_tolower(*n);
		if (ft_isdigit(*n))
			result += ((*n++) - '0') * (pow(16, --len));
		else
			result += ((*n++) - 'a' + 10) * (pow(16, --len));
	}
	return (result);
}
