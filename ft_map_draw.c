/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:00:19 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/01 18:53:43 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	my_mlx_pixel_put(t_fdf *fdf_data, t_point pt)
{
	char	*dst;
	
	pt.x += fdf_data->x_move;
	pt.y += fdf_data->y_move;
	if ((pt.x > 0 && pt.x < fdf_data->win_height) && (pt.y > 0 && pt.y < fdf_data->win_width))
	{
		dst = fdf_data->buffer + (((int)pt.x ) * fdf_data->size_line + ((int)pt.y ) * (fdf_data->bits_per_pixel  / 8));
		*(unsigned int *)dst = fdf_data->color;
	}
}

void	isomet(t_point *A,t_fdf *fdf_data)
{
	if (fdf_data->izo == 1)
	{
		A->z *= fdf_data->z_move;
		A->y = (A->y - A->x) * cos(fdf_data->theta);
		A->x = (A->y + A->x) * sin(fdf_data->theta) - A->z;
	}
}

void	line(t_point A, t_point B, t_fdf *fdf_data)
{
	float	x_step;
	float	y_step;
	float	max;
	
	isomet(&A, fdf_data);
	isomet(&B, fdf_data);
	A.x = A.x * fdf_data->zoom;
	A.y = A.y * fdf_data->zoom;
	B.x = B.x * fdf_data->zoom;
	B.y = B.y * fdf_data->zoom;
	x_step = B.x - A.x;
	y_step = B.y - A.y;
	if (abs((int)x_step) > abs((int)y_step))
		max = abs((int)x_step);
	else
		max = abs((int)y_step);
	x_step /= max;
	y_step /= max;
	if (A.z == 0)
		fdf_data->color = A.color;
	else
		fdf_data->color = B.color;

	while ((int)max)
	{
		my_mlx_pixel_put(fdf_data, A);
		A.x += x_step;
		A.y += y_step;
		--max;
	}
}

void	draw_map(t_fdf *fdf_data)
{
	int x;
	int y;
	t_point **point;
	
	point = ft_matrix(fdf_data);
	ft_menu(fdf_data);
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
	free(point);
	mlx_put_image_to_window(fdf_data->mlx_ptr, fdf_data->mlx_win, fdf_data->mlx_image, 260, 0);
}
