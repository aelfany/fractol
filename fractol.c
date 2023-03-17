/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:22:16 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/16 19:55:37 by abelfany         ###   ########.fr       */
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
	int  	a;
	int 	y;
	
	x.mlx = mlx_init();
	x.width = 1250;
	x.hight = 1250;
	x.win = mlx_new_window(x.mlx, x.width, x.hight, "fractol");
	x.img = mlx_new_image(x.mlx, x.width, x.hight);
	x.addr = mlx_get_data_addr(x.img, &x.bits_per_pixel, &x.line_length,&x.endian);
	a = 0;
	while(a < x.width)
	{
		y = 0;
		while(y < x.hight)
		{
			 if(mandelbrot(a,y,x.width,x.hight) == ITR)
				my_mlx_pixel_put(&x, a ,y, 0x000000);
			else
				my_mlx_pixel_put(&x, a ,y, 0x828415);	
			y++;
		}
		a++;
	}
	mlx_put_image_to_window(x.mlx,x.win,x.img, 0, 0);
//	if()
	mlx_loop(x.mlx);
}
