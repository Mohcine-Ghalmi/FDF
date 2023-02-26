/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/26 16:42:47 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	isomet(t_point *A, double theta)
{
	A->y = (A->y - A->x) * cos(theta);
	A->x = (A->y + A->x) * sin(theta) - A->z;
}


int	main(int argc , char **argv) 
{
	t_fdf	*fdf_data;
	t_point	**point;
	
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
	draw_map(point, fdf_data);
	mlx_key_hook(fdf_data->mlx_ptr, &key, fdf_data);
	mlx_put_image_to_window(fdf_data->mlx_ptr, fdf_data->mlx_win, fdf_data->mlx_image, 0, 0);
	mlx_loop(fdf_data->mlx_ptr);
	return 0;
}

