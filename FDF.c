/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/25 18:37:19 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

// void	isomet(t_point pt, double theta)
// {
// 	B.x = (B.x - B.y) * cos(theta);
// 	B.y = (B.x + B.y) * sin(yjeya) - B.z; 
// }

void	my_mlx_pixel_put(t_fdf *fdf_data, t_point pt)
{
	char	*dst;

	dst = fdf_data->buffer + ((int)pt.y * fdf_data->size_line + (int)pt.x * (fdf_data->bits_per_pixel  / 8));
	*(unsigned int *)dst = pt.color;
}

void	line(t_point A, t_point B, t_fdf *fdf_data)
{
	float	x_step;
	float	y_step;
	float	max;
	A.x = (A.x - A.y) * cos(0.523599);
	A.y = (A.x + A.y) * sin(0.523599) - A.z;	

	B.x = (B.x - B.y) * cos(0.523599);
	B.y = (B.x + B.y) * sin(0.523599) - B.z; 
	/*----------zoom--------*/
	A.x = A.x * 30;
	A.y = A.y * 30;
	B.x = B.x * 30;
	B.y = B.y * 30;
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
				line(point[y][x], point[y][x + 1], fdf_data);
			if (y < fdf_data->height - 1)
				line(point[y][x], point[y + 1][x], fdf_data);
			y++;
		}
		x++;
	}	
	mlx_put_image_to_window(fdf_data->mlx_ptr, fdf_data->mlx_win, fdf_data->mlx_image, 0, 0);
	mlx_loop(fdf_data->mlx_ptr);
	return 0;
}

