/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bersenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:00:54 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/14 11:12:27 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_b_vars	fill_bers_struct(int *x_ys)
{
	t_b_vars	bers;

	bers.dx = x_ys[2] - x_ys[0];
	bers.dy = x_ys[3] - x_ys[1];
	bers.yi = 1;
	bers.xi = 1;
	bers.diff = 0;
	bers.y = 0;
	bers.x = 0;
	return (bers);
}

void	plot_line_low(int *x_ys, void *addr, int *img_data)
{
	t_b_vars	bers;

	bers = fill_bers_struct(x_ys);
	if (bers.dy < 0)
	{
		bers.yi = -1;
		bers.dy = -bers.dy;
	}
	bers.diff = (2 * bers.dy) - bers.dx;
	bers.y = x_ys[1];
	bers.x = x_ys[0] - 1;
	while (++bers.x < x_ys[2])
	{
		x_ys[0] = bers.x;
		x_ys[1] = bers.y;
		my_mlx_pixel_put(addr, x_ys, img_data);
		if (bers.diff > 0)
		{
			bers.y = bers.y + bers.yi;
			bers.diff = bers.diff + (2 * (bers.dy - bers.dx));
		}
		else
			bers.diff = bers.diff + 2 * bers.dy;
	}
}

void	plot_line_high(int *x_ys, void *addr, int *img_data)
{
	t_b_vars	bers;

	bers = fill_bers_struct(x_ys);
	if (bers.dx < 0)
	{
		bers.xi = -1;
		bers.dx = -bers.dx;
	}
	bers.diff = (2 * bers.dx) - bers.dy;
	bers.x = x_ys[0];
	bers.y = x_ys[1] - 1;
	while (++bers.y < x_ys[3])
	{
		x_ys[0] = bers.x;
		x_ys[1] = bers.y;
		my_mlx_pixel_put(addr, x_ys, img_data);
		if (bers.diff > 0)
		{
			bers.x = bers.x + bers.xi;
			bers.diff = bers.diff + (2 * (bers.dx - bers.dy));
		}
		else
			bers.diff = bers.diff + 2 * bers.dx;
	}
}

void	connect_dots(int *x_ys, void *addr, int *img_data)
{
	if (abs(x_ys[3] - x_ys[1]) < abs(x_ys[2] - x_ys[0]))
	{
		if (x_ys[0] > x_ys[2])
		{
			ft_swap(&x_ys[0], &x_ys[2]);
			ft_swap(&x_ys[1], &x_ys[3]);
			plot_line_low(x_ys, addr, img_data);
		}
		else
			plot_line_low(x_ys, addr, img_data);
	}
	else
	{
		if (x_ys[1] > x_ys[3])
		{
			ft_swap(&x_ys[0], &x_ys[2]);
			ft_swap(&x_ys[1], &x_ys[3]);
			plot_line_high(x_ys, addr, img_data);
		}
		else
			plot_line_high(x_ys, addr, img_data);
	}
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

/*
Ref to Bersenham's algorith:
https://en.wikipedia.org/wiki/Bresenham
*/