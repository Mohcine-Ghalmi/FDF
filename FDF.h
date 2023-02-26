/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:42:47 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/26 17:32:27 by mghalmi          ###   ########.fr       */
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

# define LEFT	65361
# define UP		65362
# define RIGHT	65363
# define DOWN	65364

# define NUMPAD_1	65436
# define NUMPAD_2	65433
# define NUMPAD_3	65435
# define NUMPAD_4	65430
# define NUMPAD_5	65437
# define NUMPAD_6	65432
# define NUMPAD_7	65429
# define NUMPAD_8	65431
# define NUMPAD_9	65434

# define NUM_1	49
# define NUM_2	50
# define NUM_3	51
# define NUM_4	52
# define NUM_5	53
# define NUM_6	54
# define NUM_7	55
# define NUM_8	56
# define NUM_9	57

# define PLUS	61
# define MINUS	45
# define SPACE	32

# define Z		122
# define X		120
# define P		112
# define I		105
# define O		111
# define L		108
# define R		114
# define A		97
# define S		115
# define D		100
# define Q		113
# define W		119
# define E		101
# define ESC    65307

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
}		t_fdf;	

t_point	**ft_matrix(char *file);
int		get_width(char *file);
int		get_height(char *file);
void	ft_mlx_give(t_fdf *fdf_data);
void	my_mlx_pixel_put(t_fdf *fdf_data, t_point pt);
void	line(t_point A, t_point B, t_fdf *fdf_data);
void	draw_map(t_point **point, t_fdf *fdf_data);
void	isomet(t_point *A, double theta);
int key(int code, t_fdf *fdf);

#endif
