/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:41:39 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/28 20:10:45 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void    clear(t_fdf *fdf_data)
{
    mlx_clear_window(fdf_data->mlx_ptr, fdf_data->mlx_win);
    mlx_destroy_image(fdf_data->mlx_ptr, fdf_data->mlx_image);
    fdf_data->mlx_image = mlx_new_image(fdf_data->mlx_ptr, fdf_data->win_width, fdf_data->win_height);
    if (!fdf_data->mlx_image)
		exit(1);
    fdf_data->buffer = mlx_get_data_addr(fdf_data->mlx_image, &fdf_data->bits_per_pixel, &fdf_data->size_line, &fdf_data->endian);
    if (!fdf_data->buffer)
		exit(1);
    draw_map(fdf_data);
}

int key(int code, t_fdf *data_fdf)
{
    if (code == ESC)
    {
        win(data_fdf);
        exit(0);
    }
    if (code == UP)
        data_fdf->x_move -= 20;
    if (code == DOWN)
        data_fdf->x_move += 20;
    if (code == LEFT)
        data_fdf->y_move -= 20;
    if (code == RIGHT)
        data_fdf->y_move += 20;
    if (code == PLUS || code == 24)
        data_fdf->zoom += 2;
    if (code == MINUS || code == 27)
        data_fdf->zoom -= 2;
    if (code == KEY_Z)
    {
        if (data_fdf->izo == 1)
            data_fdf->izo = 0;
        else
            data_fdf->izo = 1;
    }
    if (code == PAD_7)
        data_fdf->theta += 0.05;
    if (code == PAD_9)
        data_fdf->theta -= 0.05;
    if (code == PAD_8)
        data_fdf->z_move += 0.05;
    if (code == PAD_2)
        data_fdf->z_move -= 0.05;
    clear(data_fdf);
    return 0;
}