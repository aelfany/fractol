/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:39:26 by abelfany          #+#    #+#             */
/*   Updated: 2023/03/28 21:44:59 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] != '\0' && s1[a] == s2[a])
		a++;
	return (s1[a] - s2[a]);
}

int handler(int x, int y, t_mlx *k)
{
	if((x >= 0 && x <= k -> width) && (y >= 0 && y <= k->hight))
	{
		k->nt = (x - (k->width / 2.0)) / (k->width / 4.0);
		k->st = (y - (k->hight / 2.0)) / (k->hight / 4.0);
		fractal_generator(k,k->set);
	}
	
	// if((x >= 0 && x <= k -> width) && (y >= 0 && y <= k->hight))
	// {
	// 	printf("inside ->%d\n", x);
	// 	printf("inside ->%d\n", y);
	// }
	// 	printf("out win -> %d\n", x);
	// 	printf("out win ->%d\n", y);
	return(0);
}