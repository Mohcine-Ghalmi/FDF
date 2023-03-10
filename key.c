/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:41:39 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/04 16:45:13 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	clear(t_fdf *fdf_data)
{
	mlx_clear_window(fdf_data->mlx_ptr, fdf_data->mlx_win);
	fdf_data->mlx_image = mlx_new_image(fdf_data->mlx_ptr, 2000, 2000);
	if (!fdf_data->mlx_image)
		err();
	fdf_data->buffer = mlx_get_data_addr(fdf_data->mlx_image,
			&fdf_data->bits_per_pixel, &fdf_data->size_line, &fdf_data->endian);
	if (!fdf_data->buffer)
		err();
	draw_map(fdf_data);
}

int	key(int code, t_fdf *data_fdf)
{
	if (code == ESC)
		win(data_fdf);
	if (code == KEY_Z)
	{
		if (data_fdf->izo == 1)
			data_fdf->izo = 0;
		else
			data_fdf->izo = 1;
	}
	clear(data_fdf);
	return (0);
}
