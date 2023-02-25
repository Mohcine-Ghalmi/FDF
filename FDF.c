/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/25 17:55:06 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

// void	isomet(float x, float y, double theta, t_point **point)
// {
// 	x = (val->x - val->y) * cos(theta);
// 	y = (val->x + image->matrix[(int)val->y][(int)val->x]) * sin(theta);
// }

void	my_mlx_pixel_put(t_fdf *fdf_data, int x, int y)
{
	char	*dst;

	dst = fdf_data->buffer + (y * fdf_data->size_line + x * (fdf_data->bits_per_pixel  / 8));
	*(unsigned int *)dst = fdf_data->color;
}

void	line(float x1, float y1, float x2, float y2, t_fdf *fdf_data, t_point **point)
{
	float	x_step;
	float	y_step;
	float	max;
	if (point[(int)x1][(int)y1].z == 0)
		fdf_data->color = point[(int)x1][(int)y1].color;
	else
		fdf_data->color = 0x00ff;
	y1 = (x1 + y1) * sin(0.523599) - point[(int)x1][(int)y1].z;	
	x1 = (x1 - y1) * cos(0.523599);

	y2 = (x2 + y2) * sin(0.523599) - point[(int)x2][(int)y2].z; 
	x2 = (x2 - y2) * cos(0.523599);
	/*----------zoom--------*/
	x1 = x1 * 60;
	y1 = y1 * 60;
	x2 = x2 * 60;
	y2 = y2 * 60;
	/*-------------------------*/
	x_step = x2 - x1;
	y_step = y2 - y1;
	max = (abs((int)x_step) > abs((int)y_step))?abs((int)x_step): abs((int)y_step);
	x_step /= max;
	y_step /= max;
	while ((int)max)
	{
		my_mlx_pixel_put(fdf_data, (int)y1 + 750, (int)x1 + 750);
		x1 += x_step;
		y1 += y_step;
		--max;
	}
}

int	main(int argc , char **argv)
{
	t_fdf	*fdf_data;
	t_point	**point;
	int x;
	int y;
	
	if (argc < 2)
	{
		write(1, "Usage: ./fdf [map_file]\n", 24);
		exit(1);
	}
	fdf_data = (t_fdf *)malloc(sizeof(t_fdf));
	ft_mlx_give(fdf_data);
	point = ft_matrix(argv[1]);
	fdf_data->width = get_width(argv[1]);
	fdf_data->height = get_height(argv[1]);
	x = 0;
	while (x < fdf_data->width)
	{
		y = 0;
		while (y < fdf_data->height)
		{
			if (x < fdf_data->width - 1)
				line(y, x, y,  x + 1, fdf_data, point);
			if (y < fdf_data->height - 1)
				line(y, x, y + 1,  x, fdf_data, point);
			y++;
		}
		x++;
	}	
	mlx_put_image_to_window(fdf_data->mlx_ptr, fdf_data->mlx_win, fdf_data->mlx_image, 0, 0);
	mlx_loop(fdf_data->mlx_ptr);
	return 0;
}

