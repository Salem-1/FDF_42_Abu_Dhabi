/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:00:16 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/14 11:08:56 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_operations(int ***map)
{
	t_vars	vars;
	int		img_data[3];
	void	*img;
	void	*addr;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1900, 1080, "fdf");
	img = mlx_new_image(vars.mlx, 1900, 1080);
	addr = mlx_get_data_addr(img, &img_data[0], &img_data[1], &img_data[2]);
	plot_map(map, addr, (int *)img_data);
	clean_map(map);
	mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, close_with_esc, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_with_x, &vars);
	mlx_loop(vars.mlx);
}

int	close_with_esc(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
		return (0);
	}
	return (0);
}

int	close_with_x(t_vars *vars)
{
	(void)vars;
	exit(1);
	return (0);
}

void	my_mlx_pixel_put(void *addr, int *x_ys, int *img_data)
{
	char	*dst;
	int		x;
	int		y;

	x = x_ys[0];
	y = x_ys[1];
	if (x > 0 && y > 0 && x <= 1900 && y <= 1080)
	{
		dst = addr + (y * img_data[1] + x * (img_data[0] / 8));
		*(unsigned int *)dst = x_ys[4];
	}
}
