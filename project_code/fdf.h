/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:51:08 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/09 17:15:06 by ahsalem          ###   ########.fr       */
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

int		splitted_counter(char **split_result);
int		get_line_number(char *file_name);
int		***parse_me(int fd, int n_lines);
void	isometric_projection(int ***map, float a, float b, float g);
void	connect_dots(int *x_ys, void *addr, int *img_data);
void	fill_map_horizontal(int ***map, void *addr, int *img_data);
void	my_mlx_pixel_put(void *adrr, int *x_ys, int *img_data);
void	mlx_operations(int ***map);
void	plotLineLow(int *x_ys, void *addr, int *img_data);
void	plotLineHigh(int *x_ys, void *addr, int *img_data);
void	connect_dots(int *x_ys, void *addr, int *img_data);
int		ft_atox(char *n);
//void	fill_map_vertical(int ***map, void *addr, int *img_data);
#endif