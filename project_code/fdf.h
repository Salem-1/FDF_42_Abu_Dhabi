/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:51:08 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/14 09:51:42 by ahsalem          ###   ########.fr       */
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

typedef struct bersenham_vars
{
	int	dx;
	int	dy;
	int	yi;
	int	diff;
	int	y;
	int	x;
	int	xi;

} b_vars;

int		splitted_counter(char **split_result);
int		get_line_number(char *file_name);
int		***parse_me(int fd, int n_lines);
int		fill_map(int fd,int	***map, int	i);
int		fill_map_helper(int ***map, int *counter,char **split_result);
int		fill_coordinate(int	i, int ***map, int *counters, char **split_result);
void	isometric_projection(int ***map);
void	rotate_matrix(int ***map, int i, int j, float *angels);
void	connect_dots(int *x_ys, void *addr, int *img_data);
void	fill_map_horizontal(int ***map, void *addr, int *img_data);
void	my_mlx_pixel_put(void *adrr, int *x_ys, int *img_data);
void	mlx_operations(int ***map);
void	plotlinelow(int *x_ys, void *addr, int *img_data);
void	plotlinehigh(int *x_ys, void *addr, int *img_data);
void	connect_dots(int *x_ys, void *addr, int *img_data);
int		ft_atox(char *n);
int		get_scaler(int ***map, int n_lines, int check_z, int tmp);
int 	close_with_esc (int keycode, t_vars *vars);
int 	close_with_x (t_vars *vars);
void	clean_map(int ***map);
void	rotate_x(float theta, int **node);
void	rotate_y(float theta, int **node);
void	rotate_z(float theta, int **node);
int		scale_ratio(int	n_lines, int flag, int check_z);
void	scale_map(int ***map,int n_lines);
void	free_split(char **split);
void	ft_swap(int *a, int *b);
//void	fill_map_vertical(int ***map, void *addr, int *img_data);
#endif