/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:39:26 by abelfany          #+#    #+#             */
/*   Updated: 2023/04/08 23:39:15 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_mlx *x)
{
	mlx_destroy_window(x->mlx, x->win);
	exit(0);
}

int	key_handler(int a, t_mlx *x)
{
	if (a == 123 || a == 124 || a == 126 || a == 125)
	{
		if (a == 124)
			x->move_left -= 5;
		if (a == 123)
			x->move_left += 5;
		if (a == 126)
			x->move_right += 5;
		if (a == 125)
			x->move_right -= 5;
		fractal_generator(x);
	}
	return (a);
}

int	zoom_handler(int a, int j, int y, t_mlx *x)
{
	x->zo0m = 1;
	if (a == 5 && x->zo0m == 1)
	{
		x->zoom_hight /= 2;
		x->zoom_width /= 2;
		x->p -= ((j + x->move_left) * x->zoom_hight);
		x->pp -= ((y + x->move_right) * x->zoom_width);
	}
	else if (a == 4 && x->zo0m == 1)
	{
		x->p += (j * x->zoom_hight);
		x->pp += (y * x->zoom_width);
		x->zoom_hight *= 2;
		x->zoom_width *= 2;
	}
	fractal_generator(x);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] != '\0' && s1[a] == s2[a])
		a++;
	return (s1[a] - s2[a]);
}

int	handler(int x, int y, t_mlx *k)
{
	if ((x >= 0 && x <= k -> width) && \
		(y >= 0 && y <= k->hight) && k -> zo0m == 0)
	{
		k->nt = (x - (k->width / 2.0)) / (k->width / 4.0);
		k->st = (y - (k->hight / 2.0)) / (k->hight / 4.0);
		fractal_generator(k);
	}
	return (0);
}
