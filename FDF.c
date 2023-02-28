/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/28 16:50:27 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	isomet(t_point *A,t_fdf *fdf_data)
{
	if (fdf_data->izo == 1)
	{
		A->y = (A->y - A->x) * cos(fdf_data->theta);
		A->x = (A->y + A->x) * sin(fdf_data->theta) - (A->z);
	}
}

int	main(int argc , char **argv) 
{
	t_fdf	*fdf_data;
	
	if (argc < 2)
	{
		write(1, "\033[1;31m Usage: ./fdf [map_file]\n", 23);
		exit(1);
	}
	fdf_data = (t_fdf *)malloc(sizeof(t_fdf));
	defaults(fdf_data);
	ft_mlx_give(fdf_data);
	fdf_data->width = get_width(argv[1]);
	fdf_data->height = get_height(argv[1]);
	fdf_data->file = argv[1];
	draw_map(fdf_data);
	mlx_key_hook(fdf_data->mlx_win, &key, fdf_data);
	mlx_loop(fdf_data->mlx_ptr);
	return 0;
}

