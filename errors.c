/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:18:24 by abelfany          #+#    #+#             */
/*   Updated: 2023/04/07 23:24:05 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(char *s)
{
	int	a;

	a = 0;
	while (s[a])
	{
		write(1, &s[a], 1);
		a++;
	}
}

void	error_case(void)
{
	ft_putstr("\033[0;105m\033[1;92m* ");
	ft_putstr("***********************************************\
****************************************************\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m*                            ");
	ft_putstr("-> (: Welcome to this fractal generator :)\
	<-                          *\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m*                            ");
	ft_putstr("     if you want to display fractal\
                                    *\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m* ");
	ft_putstr("to display Mandelbrot set type :                 \
                                                 *\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m* ");
	ft_putstr("-> ./fractol mandelbrot                          \
                                                 *\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m* ");
	ft_putstr("to display Burning Ship set type :               \
                                                 *\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m* ");
	ft_putstr("-> ./fractol burning_ship                        \
                                                 *\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m* ");
	ft_putstr("to display julia sets type :                     \
                                                 *\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m* ");
	ft_putstr("-> ./fractol julia (you can choose any Julia set \
you want by moving the mouse inside the window)  *\033[0;33m\n");
	ft_putstr("\033[0;105m\033[1;92m* ");
	ft_putstr("*************************************************\
**************************************************\033[0;33m\n");
	exit(0);
}
