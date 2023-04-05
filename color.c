/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:34:22 by abelfany          #+#    #+#             */
/*   Updated: 2023/04/05 00:09:00 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	color_gn(t_mlx *x)
{
	x->i = 255 - (x->i / ITR) * 255;
	my_mlx_pixel_put(x, x->a, x->y, x->i * 300);
}

void	color_gn1(t_mlx *x)
{
	x->i = 255 - (x->i / ITR) * 255;
	my_mlx_pixel_put(x, x->a, x->y, x->i * 500);
}

void	color_gn2(t_mlx *x)
{
	x->i = 255 - (x->i / ITR) * 255;
	my_mlx_pixel_put(x, x->a, x->y, x->i * 150);
}

void	color_order(t_mlx *x)
{
	if (x->color == 0)
		color_gn(x);
	if (x->color == 2)
		color_gn1(x);
	if (x->color == 3)
		color_gn2(x);
}
