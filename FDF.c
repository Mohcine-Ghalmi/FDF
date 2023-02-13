/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/13 16:30:14 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	bresenham_algo(int x1, int y1, int x2, int y2)
{
	fdf *val_fdf;
	int dx;
	int	dy;
	int px;
	
	val_fdf = (fdf *)malloc(sizeof(fdf));
	val_fdf->x = x1;
	val_fdf->y = y1;
	dx = x2 - x1; 
	dy = y2 - y1;
	px = 2 * (dx - dy); // first pixel 
	val_fdf->mlx_ptr = mlx_init();
	val_fdf->mlx_win = mlx_new_window(val_fdf->mlx_ptr, 900, 900, "FDF");
	while (val_fdf->x <= x2)
	{
		mlx_pixel_put(val_fdf->mlx_ptr, val_fdf->mlx_win, val_fdf->x, val_fdf->y, 0xFFFFFFF);
		val_fdf->x++;
		if (px < 0) // px(next) - px < 0
			px = px + 2 * dy;
		else // px(next) - px > 0
		{
			px = px + 2 * dy - 2 * dy;
			val_fdf->y++;
		}
	}
	mlx_loop(val_fdf->mlx_ptr);
}

// void	bresenham_algo(float x1, float y1, float x2, float y2)
// {
// 	fdf *val;
// 	int x_step;
// 	int y_step;
// 	int max;

// 	val = (fdf *)malloc(sizeof(fdf));
// 	x_step = x2 - x1;
// 	y_step = y2 - y1;
// 	max = (abs(x_step) > abs(y_step))? abs(x_step):abs(y_step);
// 	x_step /= max;
// 	y_step /= max;
// 	val->mlx_ptr = mlx_init();
// 	val->mlx_win = mlx_new_window(val->mlx_ptr, 900, 900, "fdf");
// 	while ((int)(x2 - x1) || (int)(y2 - y1))
// 	{
// 		mlx_pixel_put(val->mlx_ptr, val->mlx_win, x1, y1, 0xffffff);
// 		x1 += x_step;
// 		y1 += y_step;
// 	}
// 	mlx_loop(val->mlx_ptr);
// }

int main(int argc, char **argv)
{	
	float i;
	float j;

	i = 250;
	j = 250;
	if (argc >= 1)
		while (i < get_width(argv[1]) + 250)
		{
			j = 250;
			while(j < get_height(argv[1]) + 250)
			{
				bresenham_algo(i, j, i + 250, j);
				bresenham_algo(i, j, i, j + 250);
				j++;
			}
			i++;
		}	
   return (0);
}
