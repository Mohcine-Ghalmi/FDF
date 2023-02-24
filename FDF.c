/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/24 17:02:13 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

// void	isomet(float x, float y, double theta, img *image)
// {
// 	val->x = (val->x - val->y) * cos(theta);
// 	val->y = (val->x + image->matrix[(int)val->y][(int)val->x]) * sin(theta) - val->y; // z is the hight of the point
// }

void	line(float x1, float y1, float x2, float y2, t_fdf *fdf_data, t_point **point)
{
	float	x_step;
	float	y_step;
	float	max;
	// isomet(x1, y1, 0.8);
	// isomet(x2, y2, 0.8);
	/*----------zoom--------*/
	x1 = x1 * 30;
	y1 = y1 * 30;
	x2 = x2 * 30;
	y2 = y2 * 30;
	/*-------------------------*/
	x_step = x2 - x1;
	y_step = y2 - y1;
	max = (abs((int)x_step) > abs((int)y_step))?abs((int)x_step): abs((int)y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x2 - x1) || (int)(y2 - y1))
	{
		fdf_data->pixel_ptr = (unsigned int *)&fdf_data->buffer[(int)(y1 * fdf_data->size_line) + (int)(x1 * (fdf_data->bits_per_pixel / 8))];
		*fdf_data->pixel_ptr = point[(int)x1][(int)y1].color;
		x1 += x_step;
		y1 += y_step;
	}
}

int	main(int argc , char **argv)
{
	t_fdf	*fdf_data;
	t_point	**point;
	
	int x;
	int y;
	(void)argv;
	if (argc < 2)
	{
		write(1, "Usage: ./fdf [map_file]\n", 24);
		exit(1);
	}
	fdf_data = (t_fdf *)malloc(sizeof(t_fdf));
	ft_mlx_give(fdf_data);
	point = ft_matrix(argv[1]);
	x = 0;
	while (x <= get_width(argv[1]))
	{
		y = 0;
		while (y <= get_height(argv[1]))
		{
			if (x < get_width(argv[1]))	
				line(point[x][y].x, point[x][y].y, point[x][y].x + 1, point[x][y].y, fdf_data, point);
			if (y < get_height(argv[1]))
				line(point[x][y].x, point[x][y].y, point[x][y].x , point[x][y].y + 1, fdf_data, point);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf_data->mlx_ptr, fdf_data->mlx_win, fdf_data->mlx_image, 0, 0);
	mlx_loop(fdf_data->mlx_ptr);
	return 0;
}

