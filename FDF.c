/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohcine <mohcine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/04 00:17:42 by mohcine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include <string.h>

int main()
{
    void    *mlx_ptr;
    void    *mlx_win;
    int x;
    int y;

    y = 10;
    x = 0;
    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 900, 900, "FDF");
    while (y < 900)
    {
        while (x < 900)
            mlx_pixel_put(mlx_ptr, mlx_win, x++, y, 0xFFFFFF);
        x = 0;
        y += 10;
    }
    x = 0;
    y = 10;
    while (y < 900)
    {
        while (x < 900)
            mlx_pixel_put(mlx_ptr, mlx_win, y, x++, 0xFFFFFF);
        x = 0;
        y += 10;
    }
    mlx_loop(mlx_ptr);
}