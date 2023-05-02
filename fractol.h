/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:19:37 by abelfany          #+#    #+#             */
/*   Updated: 2023/04/08 17:23:22 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ITR 100
# define MAX 2.0

# include <libc.h>
# include <math.h>
# include <mlx.h>

typedef struct s_mlx
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		hight;
	int		width;
	int		color;
	double	move_right;
	double	move_left;
	double	zoom_hight;
	double	zoom_width;
	double	zo0m;
	double	pp;
	double	p;
	double	a;
	double	y;
	double	x;
	double	i;
	double	st;
	double	nt;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*set;
}	t_mlx;

typedef struct s_mnbt
{
	double	k;
	double	i;
	double	r;
	double	j;
	int		color;
}	t_mnbt;

void	color_order(t_mlx *x);
int		close_handler(t_mlx *x);
void	error_case(void);
int		key_handler(int a, t_mlx *x);
int		mandelbrot(double j, double y, t_mlx *x);
int		julia(double j, double y, t_mlx *x);
void	fractal_generator(t_mlx *x);
int		ft_strcmp(char *s1, char *s2);
int		burning(double j, double y, t_mlx *x);
int		handler(int x, int y, t_mlx *k);
int		zoom_handler(int a, int j, int y, t_mlx *x);

#endif
