/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:33:01 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/05 16:31:46 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	ft_menu(t_fdf *fdf_data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf_data->mlx_ptr;
	win = fdf_data->mlx_win;
	mlx_string_put(mlx, win, 65, y += 20, 0xff0000, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, 0xff0000, "Zoom: +/-");
	mlx_string_put(mlx, win, 15, y += 30, 0xff0000, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, 0xff0000, "Rotate: 7 / 9");
	mlx_string_put(mlx, win, 15, y += 25, 0xff0000, "move Z: 8 / 2");
	mlx_string_put(mlx, win, 15, y += 30, 0xff0000, "Projection");
	mlx_string_put(mlx, win, 57, y += 25, 0xff0000, "ISO: Z Key");
	mlx_string_put(mlx, win, 57, y += 25, 0xff0000, "Parallel: Z Key");
}
