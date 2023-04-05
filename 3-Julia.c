/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-Julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:55:43 by abelfany          #+#    #+#             */
/*   Updated: 2023/04/04 23:35:15 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double j, double y, t_mlx *x)
{
	t_mnbt	m;
	double	a;
	double	b;
	double	c;

	c = 0.0;
	a = (j * x->zoom_width) - x->p;
	b = (y * x->zoom_hight) - x->pp;
	m.j = a;
	m.k = b;
	while (c < ITR)
	{
		m.r = a * a - b * b;
		m.i = 2 * b * a;
		a = m.r + x->st;
		b = m.i + x->nt;
		if ((a * a) + (b * b) > 4)
			break ;
		c++;
	}
	return (c);
}
