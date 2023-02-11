/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/11 13:43:15 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int main()
{
    void    *mlx_ptr;
    void    *mlx_win;
    int x, x1, x2;
    int y, y1, y2;
    int dx, dy;
    
    x1 = 250;
    x2 = 450;
    y1 = 250;
    y2 = 650;

    x = x1;
    y = y1;    
    dx = x2 - x1;
    dy = y2 - y1;
    int p = 2 * dx - dy;
    
    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 900, 900, "FDF");
    while (x <= x2)
    {
        mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xFFFFFF);
        x++;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            p = p + 2 * dy - 2 * dy;
            y++;
        }
    }
    
    while (x <= x2)
    {
        mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xFFFFFF);
        x++;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            p = p + 2 * dy - 2 * dy;
            y++;
        }
    }
    mlx_loop(mlx_ptr);
}