/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:21:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/05 16:22:17 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	defaults(t_fdf *fdf_data)
{
	fdf_data->win_height = 2000;
	fdf_data->win_width = 2000;
	fdf_data->theta = 0.523599;
	fdf_data->izo = 1;
	fdf_data->x_move = fdf_data->win_height / 3;
	fdf_data->y_move = fdf_data->win_width / 3;
	fdf_data->z_move = 1;
	if (fdf_data->height > 40 || fdf_data->width > 40)
		fdf_data->zoom = 3;
	else
		fdf_data->zoom = 30;
}

void	err(void)
{
	write(1, "\033[1;31m fdf error!!\n", 21);
	exit(1);
}

void	ft_mlx_give(t_fdf *fdf_data)
{
	fdf_data->mlx_ptr = mlx_init();
	if (!fdf_data->mlx_ptr)
		err();
	fdf_data->mlx_win = mlx_new_window(fdf_data->mlx_ptr, fdf_data->win_width,
			fdf_data->win_height, "FDF");
	if (!fdf_data->mlx_win)
		err();
	fdf_data->mlx_image = mlx_new_image(fdf_data->mlx_ptr, 2000, 2000);
	if (!fdf_data->mlx_image)
		err();
	fdf_data->buffer = mlx_get_data_addr(fdf_data->mlx_image,
			&fdf_data->bits_per_pixel, &fdf_data->size_line, &fdf_data->endian);
	if (!fdf_data->buffer)
		err();
}

void	image_put(t_fdf *fdf_data)
{
	mlx_put_image_to_window(fdf_data->mlx_ptr,
		fdf_data->mlx_win, fdf_data->mlx_image, 0, 0);
}
