/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:19:37 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/13 19:00:17 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ITR 80
# define MAX 2.0

#include<libc.h>
#include<math.h>
#include<mlx.h>

typedef struct s_mlx
{
    char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    int x;
    int y;
    int hight;
    int weight;
    int a;
    char *str;
    void *mlx;
    void *win;
    void *img;
    
}   t_mlx;

typedef struct s_lst
{
    char *str;
    struct s_lst *next;
}   t_lst;

long long           ft_atoi(const char *str);
double              mandelbrot(double x, double y, double weight, double hight);

#endif

