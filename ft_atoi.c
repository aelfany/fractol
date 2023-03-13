/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:58:21 by abelfany          #+#    #+#             */
/*   Updated: 2023/02/11 17:12:35 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
long long ft_atoi(const char *str)
{
    int x;
    int y;
    long long res;

    x = 0;
    y = 1;
    res = 0;
    if(str[x] == '-')
        y *= -1;
    if(!(str[x] >= 48 && str[x] <= 57))
        x++;
    while(str[x] >= 48 && str[x] <= 57)
    {
        res *= 10;
        res += str[x] - 48;
        x++;
    }
    return (res * y);
}