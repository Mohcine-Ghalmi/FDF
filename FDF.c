/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/11 18:36:43 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	bresenham_algo(int x1, int y1, int x2, int y2)
{
	fdf	*val_fdf;
	int dx;
	int	dy;
	int px;

	val_fdf->x = x1;
	val_fdf->y = y1;
	dx = x2 - x1;
	dy = y1 - y2;
	px = 2 * dx - dy;
	val_fdf->mlx_ptr = mlx_init();
	val_fdf->mlx_ptr = mlx_new_window(val_fdf->mlx_ptr, 900, 900, "FDF");
	while (val_fdf->x <= x2)
	{
		mlx_pixel_put(val_fdf->mlx_ptr, val_fdf->mlx_win, val_fdf->x, val_fdf->y, 0xFFFFFF);
		val_fdf->x++;
		if (px < 0)
			px = px + 2 *dy;
		else
		{
			px = px + 2 * dy - 2 * dy;
			val_fdf->y++;	
		}
	}
	mlx_loop(val_fdf->mlx_win);
}

int main()
{
   bresenham_algo(250, 450, 250, 650);
   return (0);
}