/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:21:48 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/24 16:41:20 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FDF.h"

void	ft_mlx_give(t_fdf *fdf_data)
{
	fdf_data->mlx_ptr = mlx_init();
	fdf_data->mlx_win = mlx_new_window(fdf_data->mlx_ptr, 900, 900, "FDF");
	fdf_data->mlx_image = mlx_new_image(fdf_data->mlx_ptr, 900, 900);
	fdf_data->buffer = mlx_get_data_addr(fdf_data->mlx_image, &fdf_data->bits_per_pixel, &fdf_data->size_line, &fdf_data->endian);
}