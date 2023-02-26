/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:16:22 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/26 14:10:07 by mghalmi          ###   ########.fr       */
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

void	fill_matrix(t_point **matrix_line, int line_count, char *line)
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
		{
			if (matrix_line[line_count][col].z > 0)
				matrix_line[line_count][col].color = 0xff0000;
			else
				matrix_line[line_count][col].color = 0xffffff;		
		}
		free(nbrs[col]);
		col++;
	}
	free(nbrs[col]);
}

t_point	**ft_matrix(char *file)
{
	t_point		**matrix;
	int		fd;
	int		line_count;
	char	*line;


	matrix = (t_point **)malloc(get_height(file) * sizeof(t_point *));
	line_count = 0;
	while (line_count < get_height(file))
	{
		matrix[line_count] = (t_point *)malloc(get_width(file)
				* sizeof(t_point));
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

// int main(int argc, char **argv)
// {
// 	int x;
// 	int y;
// 	int width = get_width(argv[1]);
// 	t_point **point;

// 	printf("height = %d width = %d\n", get_height(argv[1]), get_width(argv[1]));
// 	point = ft_matrix(argv[1]);
// 	x = 0;
	
// 		y = 0;
// 		while (y < width)
// 		{
// 			printf("x=%3f y=%3f z=%3f  color=%3d\n", point[x][y].x, point[x][y].y, point[x][y].z, point[x][y].color);
// 			y++;
// 		}	
// }