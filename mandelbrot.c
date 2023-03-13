/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:35 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/13 19:00:27 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double mandelbrot(double x, double y, double weight, double hight)
{
    int a;
    // int x;
    int c;
    // double x;
    // double y;
    a = x / (weight / 4);
    a = y / (hight / 4);
    while(a < ITR)
    {
        
    }
    return (x);
}
