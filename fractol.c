/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:22:16 by abelfany          #+#    #+#             */
/*   Updated: 2023/04/05 00:13:57 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

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

int	key_code(int a, t_mlx *x)
{
	if (a == 53)
		exit(0);
	if (a == 12 && (x->zo0m == 0))
		x->zo0m = 1;
	else if (a == 12 && (x->zo0m == 1))
		x->zo0m = 0;
	else if (a == 48)
	{
		if (x->color == 0)
			x->color = 2;
		else if (x->color == 2)
			x->color = 3;
		else if (x->color == 3)
			x->color = 0;
		fractal_generator(x);
	}
	else
		return (key_handler(a, x));
	return (a);
}

void	fractal_generator(t_mlx *x)
{
	if (x->img != NULL)
		mlx_destroy_image(x->mlx, x->img);
	x->img = mlx_new_image(x->mlx, x->width, x->hight);
	x->addr = mlx_get_data_addr(x->img, \
		&x->bits_per_pixel, &x->line_length, &x->endian);
	x->a = 0;
	while (x->a < x->width)
	{
		x->y = 0;
		while (x->y < x->hight)
		{
			if (ft_strcmp(x->set, "burning_ship") == 0)
				x->i = burning(x->a + x->move_left, x->y + x->move_right, x);
			else if (ft_strcmp(x->set, "mandelbrot") == 0)
				x->i = mandelbrot(x->a + x->move_left, x->y + x->move_right, x);
			else if (ft_strcmp(x->set, "julia") == 0)
				x->i = julia(x->a + x->move_left, x->y + x->move_right, x);
			else
				error_case();
			color_order(x);
			x->y++;
		}
		x->a++;
	}
	mlx_put_image_to_window(x->mlx, x->win, x->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_mlx	x;

	if (ac == 2)
	{
		x.zo0m = 0;
		x.set = av[1];
		x.mlx = mlx_init();
		x.width = 800;
		x.hight = 800;
		x.color = 0;
		x.move_left = 0.0;
		x.move_right = 0.0;
		x.img = NULL;
		x.win = mlx_new_window(x.mlx, x.width, x.hight, "fractol");
		x.zoom_width = (4.0 / x.width);
		x.zoom_hight = (4.0 / x.hight);
		x.p = 2;
		x.pp = 2;
		mlx_key_hook(x.win, &key_code, &x);
		mlx_mouse_hook(x.win, &zoom_handler, &x);
		mlx_hook(x.win, 6, 0, handler, &x);
		fractal_generator(&x);
		mlx_loop(x.mlx);
	}
	else
		error_case();
}
