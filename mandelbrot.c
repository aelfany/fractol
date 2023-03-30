/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:35 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/30 15:47:15 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(double j, double y, t_mlx *x)
{
    t_mnbt m;
    double a;
    double b;
    double c;
    c = 0.0;
    a = (j - (x->width / 2)) / (x->width / 4);
    b = (y - (x->hight / 2)) / (x->hight / 4);
    m.j = a;
    m.k = b;
    while(c < ITR)
    {
        m.r = a * a - b * b;
        m.i = 2 * b * a;
        a = m.r + m.j;
        b = m.i + m.k;
        if((a * a) + (b * b) > 4)
            break;
        c++;
    }
    return (c);
}
