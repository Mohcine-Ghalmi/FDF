/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/20 19:04:12 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	check_matrix(int x, int y, img *image, int height, int width)
{
	if (x < width && y < height)
		image->color = (image->matrix[y][x] != 0) ? 0xe80c0c : 0xffffff;
	else 
		image->color = 0xffffff;
}

void	line(float x1, float y1, float x2, float y2, img *image)
{
	float	x_step;
	float	y_step;
	float	max;
	// image->color = (image->matrix[(int)y1][(int)x1] > 0) ? 0xe80c0c : 0xffffff;
	/*----------zoom--------*/
	x1 = x1 * 30;
	y1 = y1 * 30;
	x2 = x2 * 30;
	y2 = y2 * 30;
	/*-------------------------*/
	// image->color = 0xff0000;
	x_step = x2 - x1;
	y_step = y2 - y1;
	max = (abs((int)x_step) > abs((int)y_step))?abs((int)x_step): abs((int)y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x2 - x1) || (int)(y2 - y1))
	{
		image->pixel_ptr = (unsigned int *)&image->buffer[(int)(y1 * image->size_line) + (int)(x1 * (image->bits_per_pixel / 8))];
		*image->pixel_ptr = image->color;
		x1 += x_step;
		y1 += y_step;
	}
}

int	main(int argc , char **argv)
{
	fdf	*val;
	img *image;
	float x;
	float y;
	
	if (argc < 2)
	{
		write(1, "Usage: ./fdf [map_file]\n", 24);
		exit(1);
	}
	val = (fdf *)malloc(sizeof(fdf));
	image = (img *)malloc(sizeof(img));
	val->ptr = mlx_init();
	val->win = mlx_new_window(val->ptr, 900, 900, "FDF");
	image->image = mlx_new_image(val->ptr, 900, 900);
	image->buffer = mlx_get_data_addr(image->image, &image->bits_per_pixel, &image->size_line, &image->endian);
	image->matrix = ft_matrix(argv[1]);
	x = 0;
	while (x <= get_width(argv[1]))
	{
		y = 0;
		while (y <= get_height(argv[1]))
		{
			if (x < get_width(argv[1]))	
			{
				check_matrix(x, y, image, get_height(argv[1]), get_width(argv[1]));
				line(x, y, x + 1, y, image);
			}
			if (y < get_height(argv[1]))
			{
				check_matrix(x, y, image, get_height(argv[1]), get_width(argv[1]));
				line(x, y, x , y + 1, image);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(val->ptr, val->win, image->image, 100, 100);
	mlx_loop(val->ptr);
	return 0;
}
