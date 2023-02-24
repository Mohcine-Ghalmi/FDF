/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:16:22 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/24 15:57:30 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		perror("open");
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_isprint(*line))
			height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		perror("open");
		exit(1);
	}
	line = get_next_line(fd);
	width = count_words(line, ' ');
	close(fd);
	free(line);
	return (width);
}

void	fill_matrix(t_fdf **matrix_line, int line_count, char *line)
{
	char	**nbrs;
	char	*find;
	int		col;

	nbrs = ft_split(line, ' ');
	col = 0;
	while (nbrs[col])
	{
		matrix_line[line_count][col].z = ft_atoi(nbrs[col]);
		matrix_line[line_count][col].x = line_count;
		matrix_line[line_count][col].y = col;
		find = ft_strchr(nbrs[col], 'x');
		if (find)
			matrix_line[line_count][col].color = ft_atoi_base(find);
		else
			matrix_line[line_count][col].color = 0;
		free(nbrs[col]);
		col++;
	}
	free(nbrs[col]);
}

t_fdf	**ft_matrix(char *file)
{
	t_fdf		**matrix;
	int		fd;
	int		line_count;
	char	*line;


	matrix = (t_fdf **)malloc(get_height(file) * sizeof(t_fdf *));
	line_count = 0;
	while (line_count < get_height(file))
	{
		matrix[line_count] = (t_fdf *)malloc(get_width(file)
				* sizeof(t_fdf));
		line_count++;
	}
	fd = open(file, O_RDONLY);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(matrix, line_count, line);
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	free(line);
	close(fd);
	return (matrix);
}