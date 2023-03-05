/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:38:23 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/05 17:50:37 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void	check(char *file)
{
	if (!ft_strchr(file, '.'))
	{
		write(1, "\033[1;31m  Non valide map\n", 25);
		exit(1);
	}
}

int	key_hook(t_fdf *fdf_data)
{
	win(fdf_data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf_data;

	if (argc != 2)
	{
		write(1, "\033[1;31m Usage: ./fdf [map_file]\n", 33);
		exit(1);
	}
	check(argv[1]);
	fdf_data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf_data)
		exit(1);
	fdf_data->file = argv[1];
	fdf_data->height = get_height(fdf_data->file, &fdf_data->width);
	defaults(fdf_data);
	ft_mlx_give(fdf_data);
	draw_map(fdf_data);
	mlx_key_hook(fdf_data->mlx_win, &key, fdf_data);
	mlx_hook(fdf_data->mlx_win, 17, 0, key_hook, fdf_data);
	mlx_loop(fdf_data->mlx_ptr);
	return (0);
}
