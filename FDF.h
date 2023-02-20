/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:42:47 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/19 15:47:45 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

int	**ft_matrix(char *file);
int	get_width(char *file);
int	get_height(char *file);

typedef struct FDF
{
    void    *ptr;
    void    *win;
    int     x;
    int     y;
}   fdf;

typedef struct image
{
    int     *image;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
    char    *buffer;
    int     color;
    unsigned int *pixel_ptr;
    int     **matrix;
}       img;


#endif
