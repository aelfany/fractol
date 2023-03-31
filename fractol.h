/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:19:37 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/31 21:28:02 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ITR 100
# define MAX 2.0

#include<libc.h>
#include<math.h>
#include<mlx.h>

typedef struct s_mlx
{
	int     bits_per_pixel;
	int     line_length;
	int     endian;
    int     hight;
    int     width;
    char    *addr;
    char    *set;
    void    *mlx;
    void    *win;
    void    *img;
    int  zo0m;
    int  handler;
    double  a;
	double  y;
	double  x;
	double  i;
    double st;
    double nt;
}   t_mlx;

typedef struct s_mnbt
{
    double k;
    double i;
    double r;
    double j;
    int color;
}   t_mnbt;

typedef struct s_lst
{
    char *str;
    struct s_lst *next;
}   t_lst;

int mandelbrot(double j, double y, t_mlx *x);
int julia(double j, double y, t_mlx *x);
void fractal_generator(t_mlx *x, char *set);
int	ft_strcmp(char *s1, char *s2);
int burning_ship(double j, double y, t_mlx *x);
int handler(int x, int y, t_mlx *k);
int zoom_handler(int a, t_mlx *x);
int ft_atoi(const char *str);

#endif

