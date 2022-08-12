/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:51:08 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/12 06:48:41 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

#include "printf/ft_printf.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <unistd.h>
#include <math.h>
#include "mlx/mlx.h"


typedef struct s_vars
{
	void *mlx;
	void *win;
}	t_vars;
int		splitted_counter(char **split_result);
int		get_line_number(char *file_name);
int		***parse_me(int fd, int n_lines);
void	isometric_projection(int ***map, float a, float b, float g, float c, float d);
void	connect_dots(int *x_ys, void *addr, int *img_data);
void	fill_map_horizontal(int ***map, void *addr, int *img_data);
void	my_mlx_pixel_put(void *adrr, int *x_ys, int *img_data);
void	mlx_operations(int ***map);
void	plotLineLow(int *x_ys, void *addr, int *img_data);
void	plotLineHigh(int *x_ys, void *addr, int *img_data);
void	connect_dots(int *x_ys, void *addr, int *img_data);
int		ft_atox(char *n);
int 	close_with_esc (int keycode, t_vars *vars);
int 	close_with_x (t_vars *vars);
void	clean_map(int ***map);
void	rotateX3D(float theta, int **node);
void	rotateY3D(float theta, int **node);
void	rotateZ3D(float theta, int **node);
//void	fill_map_vertical(int ***map, void *addr, int *img_data);
#endif