/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:51:08 by ahsalem           #+#    #+#             */
/*   Updated: 2022/08/06 11:53:35 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

#include "printf/ft_printf.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <unistd.h>

int splitted_counter(char **split_result);
int get_line_number(char *file_name);
int ***parse_me(int fd, int n_lines);
#endif