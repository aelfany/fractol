/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:22:16 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/13 17:41:51 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	main(void)
{
	t_mlx x;
	// char	*dst;
	double  	a;
	double 	y;
	double 	i;
	
	x.mlx = mlx_init();
	x.weight = 1024;
	x.hight = 1024;
	x.win = mlx_new_window(x.mlx, 2000, 1200, "not fractol");
	x.img = mlx_new_image(x.mlx, 2000, 1200);
	x.addr = mlx_get_data_addr(x.img, &x.bits_per_pixel, &x.line_length,&x.endian);
	// while(1)
	// {
	// 	if(test == 1)
	// 		iteration();
	// 	else
	// 		my_mlx_pixel_put(&x, y ,a, black);
			
	// }
	a = 0;
	while(a < x.hight)
	{
		y = 0;
		while(y < x.weight)
		{
			 i = mandelbrot(a,y,x.hight,x.weight);
				my_mlx_pixel_put(&x, y ,a, 0x29C1AA);
			y++;
		}
		a++;
	}
	mlx_put_image_to_window(x.mlx,x.win,x.img, 0, 0);
	mlx_loop(x.mlx);
}