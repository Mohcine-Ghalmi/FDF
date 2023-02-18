/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/18 17:33:47 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

float	val_abs(float x)
{
	return	((x > 0)? x : -x);
}

void	line(float x1, float y1, float x2, float y2, mlx *val)
{
	float	x_step;
	float	y_step;
	float	max;
	
	/*----------zoom--------*/
	x1 = x1 * 30;
	y1 = y1 * 30;
	x2 = x2 * 30;
	y2 = y2 * 30;
	/*-------------------------*/
	
	x_step = x2 - x1;
	y_step = y2 - y1;
	max = (val_abs(x_step) > val_abs(y_step))?val_abs(x_step): val_abs(y_step);
	x_step /= max;
	y_step /= max;
	val->color = 0xffffff;
	while ((int)(x2 - x1) || (int)(y2 - y1))
	{
		val->buffer[((int)y1 * val->size_line) + (int)x1 * (val->bits_per_pixel / 8)] = val->color;
		// mlx_pixel_put(val->ptr, val->win, x1, y1, 0xffffff);
		x1 += x_step;
		y1 += y_step;
	}
}

int	main(int argc , char **argv)
{
	mlx	*val;
	float x;
	float y;
	
	if (argc < 2)
	{
		write(1, "where is the map ??", 20);
		exit(1);
	}
	val = (mlx *)malloc(sizeof(mlx));
	val->ptr = mlx_init();
	val->win = mlx_new_window(val->ptr, 900, 900, "FDF");
	val->image = mlx_new_image(val->ptr, 900, 900);
	val->buffer = mlx_get_data_addr(val->ptr, &val->bits_per_pixel, &val->size_line, &val->endian);
	x = 0;
	while (x <= get_width(argv[1]))
	{
		y = 0;
		while (y <= get_height(argv[1]))
		{
			if (x < get_width(argv[1]))	
				line(x, y, x + 1, y,  val);
			if (y < get_height(argv[1]))
				line(x, y, x , y + 1, val);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(val->ptr, val->win, val->image, 0, 0);
	mlx_loop(val->ptr);
	return 0;
}
