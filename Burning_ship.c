/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:50:24 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/31 21:16:04 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int burning_ship(double j, double y, t_mlx *x)
{
    t_mnbt m;
    double a;
    double b;
    double c;
    c = 0.0;
    a = (j - (x->width / 2)) / ((x->width / 4) / 2);
    b = (y - (x->hight / 2)) / ((x->hight / 4) / 2);
    m.j = a;
    m.k = b;
    while(c < ITR)
    {
        m.r = a * a - b * b;
        m.i = 2 * b * a;
        a = m.r + x->st;
        b = m.i + x->nt;
        if((a * a) + (b * b) > 4)
            break;
        c++;
    }
    return (c);
}