/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:00:19 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/26 16:37:33 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	my_mlx_pixel_put(t_fdf *fdf_data, t_point pt)
{
	char	*dst;

	dst = fdf_data->buffer + (((int)pt.x + 250 ) * fdf_data->size_line + ((int)pt.y  + 250) * (fdf_data->bits_per_pixel  / 8));
	*(unsigned int *)dst = pt.color;
}

void	line(t_point A, t_point B, t_fdf *fdf_data)
{
	float	x_step;
	float	y_step;
	float	max;
	
	isomet(&A, 0.5);
	isomet(&B, 0.5);
	/*----------zoom--------*/
	A.x = A.x * 15;
	A.y = A.y * 15;
	B.x = B.x * 15;
	B.y = B.y * 15;
	/*-------------------------*/
	x_step = B.x - A.x;
	y_step = B.y - A.y;
	max = (abs((int)x_step) > abs((int)y_step))?abs((int)x_step): abs((int)y_step);
	x_step /= max;
	y_step /= max;
	while ((int)max)
	{
		my_mlx_pixel_put(fdf_data, A);
		A.x += x_step;
		A.y += y_step;
		--max;
	}
}

void	draw_map(t_point **point, t_fdf *fdf_data)
{
	int x;
	int y;
	
	x = 0;
	while (x < fdf_data->width)
	{
		y = 0;
		while (y < fdf_data->height)
		{
			if (x < fdf_data->width - 1)
				line(point[y][x], point[y][x + 1], fdf_data);
			if (y < fdf_data->height - 1)
				line(point[y][x], point[y + 1][x], fdf_data);
			y++;
		}
		x++;
	}
}