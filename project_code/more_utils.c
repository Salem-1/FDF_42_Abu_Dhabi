/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:24:10 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/14 11:18:13 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_map(int ***map, void *addr, int *img_data)
{
	t_map_filler	m_vars;

	m_vars.move_image = 500;
	m_vars.i = -1;
	m_vars.j = -1;
	m_vars.k = -1;
	while (map[++m_vars.i])
	{
		while (map[m_vars.i][++m_vars.j] && map[m_vars.i])
		{
			if (map[m_vars.i][m_vars.j + 1])
				fill_horizontal(map, addr, img_data, m_vars);
			if (map[m_vars.i + 1])
				fill_vertical(map, addr, img_data, m_vars);
		}
		m_vars.j = -1;
	}	
}

void	fill_horizontal(int ***map, void *addr,
			int *img_data, t_map_filler m_vars)
{
	m_vars.x_ys[0] = map[m_vars.i][m_vars.j][0] + m_vars.move_image ;
	m_vars.x_ys[1] = map[m_vars.i][m_vars.j][1] + m_vars.move_image;
	m_vars.x_ys[2] = map[m_vars.i][m_vars.j + 1][0] + m_vars.move_image ;
	m_vars.x_ys[3] = map[m_vars.i][m_vars.j + 1][1] + m_vars. move_image;
	if (map[m_vars.i][m_vars.j + 1][3] > map[m_vars.i][m_vars.j][3])
		m_vars.x_ys[4] = map[m_vars.i][m_vars.j + 1][3];
	else
		m_vars.x_ys[4] = map[m_vars.i][m_vars.j][3];
	connect_dots(m_vars.x_ys, addr, img_data);
}

void	fill_vertical(int ***map, void *addr,
			int *img_data, t_map_filler m_vars)
{
	m_vars.x_ys[0] = map[m_vars.i][m_vars.j][0] + m_vars.move_image;
	m_vars.x_ys[1] = map[m_vars.i][m_vars.j][1] + m_vars.move_image;
	m_vars.x_ys[2] = map[m_vars.i + 1][m_vars.j][0] + m_vars.move_image;
	m_vars.x_ys[3] = map[m_vars.i + 1][m_vars.j][1] + m_vars.move_image;
	if (map[m_vars.i + 1][m_vars.j][3] > map[m_vars.i][m_vars.j][3])
		m_vars.x_ys[4] = map[m_vars.i + 1][m_vars.j][3];
	else
		m_vars.x_ys[4] = map[m_vars.i][m_vars.j][3];
	connect_dots(m_vars.x_ys, addr, img_data);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
