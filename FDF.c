/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/14 16:53:22 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	line(float x1, float y1, float x2, float y2, fdf *val)
{
	float	x_step;
	float	y_step;
	float	max;
	
	x1 = x1 * 30;
	x2 = x2 * 30;
	y1 = y1 * 30;
	y2 = y2 * 30;
	val->x = x1;
	val->y = y1;
	x_step = x2 - x1;
	y_step = y2 - y1;
	max = (abs(x_step) > abs(y_step))?abs(x_step): abs(y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x2 - val->x) || (int)(y2 - val->y))
	{
		mlx_pixel_put(val->mlx_ptr, val->mlx_win, val->x, val->y,0xff0000);
		val->x += x_step;
		val->y += y_step;
	}
}

int	main(int argc , char **argv)
{
	fdf	*val;
	float x;
	float y;
	int i, j;

	i = 0;
	j = 0;
	
	x = 0;
	y = 0;
	val = (fdf *)malloc(sizeof(fdf));
	val->matrix = matrix(argv[1]);
	val->mlx_ptr = mlx_init();
	val->mlx_win = mlx_new_window(val->mlx_ptr, 900, 900, "FDF");
	while (x <= get_width(argv[1]))
	{
		y = 0;
		j = 0;
		while (y <= get_height(argv[1]))
		{
			if (x < get_width(argv[1]))	
				line(x, y, x + 1, y, val);
			if (y < get_height(argv[1]))
				line(x, y, x , y + 1, val);
			y++;
			j++;
		}
		i++;
		x++;
	}
	mlx_loop(val->mlx_ptr);
	return 0;
}
