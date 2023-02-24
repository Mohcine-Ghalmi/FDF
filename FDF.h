/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:42:47 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/24 17:00:29 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <ctype.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

typedef struct point
{
	float	x;
	float	y;
	float	z;
	int color;
}		t_point;


typedef struct FDF
{
	float	x;
	float	y;
	float	z;
	int color;
	int	width;
	int height;
	void	*mlx_ptr;
	void	*mlx_win;
	int		endian;
	char	*buffer;
	void	*mlx_image;
	int	bits_per_pixel;
	int	size_line;
	unsigned int pixel_ptr;
}		t_fdf;	

t_point	**ft_matrix(char *file);
int		get_width(char *file);
int		get_height(char *file);
void	ft_mlx_give(t_fdf *fdf_data);

#endif
