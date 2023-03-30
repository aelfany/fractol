/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:58:21 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/22 17:14:17 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int ft_atoi(const char *str)
{
    int x;
    int y;
    int res;

    x = 0;
    y = 1;
    res = 0;
    if(str[x] == '-')
        y *= -1;
    if(!(str[x] >= 48 && str[x] <= 57))
        x++;
    while((str[x] >= 48 && str[x] <= 57) || str[x] == '.')
    {
        if(str[x] == '.')
            x++;
        res *= 10;
        res += str[x] - 48;
        x++;
    }
    // printf("%.1f\n", res);
    return (res * y);
}
// int main()
// {
//     printf("%.2f\n", ft_atoi("0.10"));
// }