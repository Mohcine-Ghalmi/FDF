/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:21:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/28 16:53:10 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FDF.h"

void    defaults(t_fdf *fdf_data)
{
    fdf_data->win_height = 900;
    fdf_data->win_width = 900;
	fdf_data->theta = 0.5;
	fdf_data->izo = 1;
	fdf_data->x_move = 450;
	fdf_data->y_move = 450;
	fdf_data->z_move = 0;
	fdf_data->zoom = 20;
}

void	ft_mlx_give(t_fdf *fdf_data)
{
	fdf_data->mlx_ptr = mlx_init();
	fdf_data->mlx_win = mlx_new_window(fdf_data->mlx_ptr, fdf_data->win_width, fdf_data->win_height, "FDF");
	fdf_data->mlx_image = mlx_new_image(fdf_data->mlx_ptr, fdf_data->win_width, fdf_data->win_height);
	fdf_data->buffer = mlx_get_data_addr(fdf_data->mlx_image, &fdf_data->bits_per_pixel, &fdf_data->size_line, &fdf_data->endian);
}
