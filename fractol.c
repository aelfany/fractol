/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:22:16 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/31 22:13:44 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void error_case(void)
{
	printf("\033[0;105m\033[1;92m* ");puts("***************************************************************************************************\033[0;33m");
	printf("\033[0;105m\033[1;92m*                       ");puts("-> (: Welcome to this fractal generator :) <-                               *\033[0;33m");                               
	printf("\033[0;105m\033[1;92m*                          ");puts("     if you want to display fractal                                      *\033[0;33m");                                                         
	printf("\033[0;105m\033[1;92m* ");puts("to display Mandelbrot set type :                                                                  *\033[0;33m");                                                                  
	printf("\033[0;105m\033[1;92m* ");puts("-> ./fractol mandelbrot                                                                           *\033[0;33m");                                                                            
	printf("\033[0;105m\033[1;92m* ");puts("to display Burning Ship set type :                                                                *\033[0;33m");                                                                  
	printf("\033[0;105m\033[1;92m* ");puts("-> ./fractol Burning Ship                                                                         *\033[0;33m");                                                                            
	printf("\033[0;105m\033[1;92m* ");puts("to display julia sets type :                                                                      *\033[0;33m");                                                                      
	printf("\033[0;105m\033[1;92m* ");puts("-> ./fractol julia (you can choose any Julia set you want by moving the mouse inside the window)  *\033[0;33m");    
	printf("\033[0;105m\033[1;92m* ");puts("***************************************************************************************************\033[0;33m");
	exit(0);
}
int fun(int a, t_mlx *x)
{
	if(a == 53)
		exit(0);
	if(a == 12 && (x->zo0m == 0))
		x->zo0m = 1;
	else if(a == 12 && (x->zo0m == 1))
		x->zo0m = 0;
	return a;
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void fractal_generator(t_mlx *x, char *set)
{
	if(x->img != NULL)
		mlx_destroy_image(x->mlx, x->img);
	x->img = mlx_new_image(x->mlx, x->width, x->hight);
	x->addr = mlx_get_data_addr(x->img, &x->bits_per_pixel, &x->line_length,&x->endian);
	x->a = 0;
	while(x->a < x->width)
	{
		x->y = 0;
		while(x->y < x->hight)
		{
			if(ft_strcmp(set,"burning_ship") == 0)
				x->i = burning_ship(x->a,x->y,x);
			else if(ft_strcmp(set,"mandelbrot") == 0)
				x->i = mandelbrot(x->a,x->y,x);
			else if(ft_strcmp(set,"julia") == 0)
				x->i = julia(x->a,x->y, x);
			else
				error_case();
			x->i = 255 - (x->i / ITR) * 255;
				my_mlx_pixel_put(x, x->a ,x->y, x->i * 300);
			if(x->i == ITR)
				my_mlx_pixel_put(x, x->a ,x->y, 0xFFFFFF);
			x->y++;
		}
		x->a++;
	}
	mlx_put_image_to_window(x->mlx,x->win,x->img, 0, 0);
}
int	main(int ac, char **av)
{
	if(ac == 2)
	{
		t_mlx x;
		x.zo0m = 0;
		x.set = av[1];
		x.mlx = mlx_init();
		x.width = 800;
		x.hight = 800;
		x.img = NULL;
		x.win = mlx_new_window(x.mlx, x.width, x.hight, "fractol");
		mlx_key_hook(x.win,&fun,&x);
		mlx_hook(x.win,6,0,handler,&x);
		//mlx_mouse_hook(x.win, zoom_handler, &x);
		fractal_generator(&x,x.set);
		mlx_loop(x.mlx);
	}
	else
		error_case();
}
