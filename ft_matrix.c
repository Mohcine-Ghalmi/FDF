/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:16:22 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/04 16:32:05 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	get_height(char *file, int *width)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		err();
	height = 0;
	line = get_next_line(fd);
	*width = count_words(line, ' ');
	while (line)
	{
		if (ft_isprint(*line))
			height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (height);
}

void	fill_matrix(t_point **matrix_line, int line_count, char *line)
{
	char	**nbrs;
	char	*find;
	int		col;

	nbrs = ft_split(line, ' ');
	col = 0;
	while (nbrs[col])
	{
		matrix_line[line_count][col].x = line_count;
		matrix_line[line_count][col].y = col;
		matrix_line[line_count][col].z = ft_atoi(nbrs[col]);
		find = ft_strchr(nbrs[col], 'x');
		if (find)
			matrix_line[line_count][col].color = ft_atoi_base(find);
		else
		{
			if (matrix_line[line_count][col].z != 0)
				matrix_line[line_count][col].color = 0xff0000;
			else
				matrix_line[line_count][col].color = 0x00ffff;
		}
		free(nbrs[col]);
		col++;
	}
	free(nbrs);
}

t_point	**alloc(t_fdf *fdf_data)
{
	int			line_count;
	t_point		**matrix;

	line_count = 0;
	matrix = (t_point **)malloc((fdf_data->height + 1) * sizeof(t_point *));
	if (!matrix)
		exit(1);
	while (line_count < fdf_data->height)
		matrix[line_count++] = (t_point *)malloc((fdf_data->width)
				* sizeof(t_point));
	return (matrix);
}

t_point	**ft_matrix(t_fdf *fdf_data)
{
	int			fd;
	int			line_count;
	char		*line;
	t_point		**matrix;

	matrix = alloc(fdf_data);
	fd = open(fdf_data->file, O_RDONLY);
	if (fd < 2)
		exit(1);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(matrix, line_count, line);
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	matrix[line_count] = 0;
	free(line);
	close(fd);
	return (matrix);
}
