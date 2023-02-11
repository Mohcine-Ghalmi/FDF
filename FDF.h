/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:42:47 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/11 18:28:43 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"

int	**matrix(char *file);
int	get_width(char *file);
int	get_height(char *file);

typedef struct FDF
{
    void    *mlx_ptr;
    void    *mlx_win;
    int     **matrix;
    int     x;
    int     y;
    
}   fdf;


#endif
