/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:34:02 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/03 18:30:40 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	win(t_fdf *data_fdf)
{
	mlx_destroy_image(data_fdf->mlx_ptr, data_fdf->mlx_image);
	mlx_destroy_window(data_fdf->mlx_ptr, data_fdf->mlx_win);
	free(data_fdf);
	exit(1);
}
