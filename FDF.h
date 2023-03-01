/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:42:47 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/01 18:53:50 by mghalmi          ###   ########.fr       */
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

# define LEFT	123
# define UP		126
# define RIGHT	124
# define DOWN	125

# define PAD_2	84
# define PAD_7	89
# define PAD_8	91
# define PAD_9	92

# define PLUS	69
# define MINUS	78
# define SPACE	49

# define ESC    53

# define KEY_Z 6

typedef struct point
{
	float	x;
	float	y;
	float	z;
	int color;
}		t_point;


typedef struct FDF
{
	int	x_move;
	int	y_move;
	float	z_move;
	int zoom;
	int izo;
	int win_height;
	int win_width;
	float	theta;
	char *file;
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

t_point	**ft_matrix(t_fdf *fdf_data);
int		get_width(char *file);
int		get_height(char *file);
void	ft_mlx_give(t_fdf *fdf_data);
void	my_mlx_pixel_put(t_fdf *fdf_data, t_point pt);
void	line(t_point A, t_point B, t_fdf *fdf_data);
void	draw_map(t_fdf *fdf_data);
void	isomet(t_point *A, t_fdf *data_fdf);
int 	key(int code, t_fdf *fdf);
void    win(t_fdf *data_fdf);
void	zoom(t_fdf *data_fdf);
void    defaults(t_fdf *fdf_data);
void	ft_menu(t_fdf *fdf_data);
void	err(void);

#endif
