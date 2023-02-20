/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:16:22 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/20 19:12:19 by mghalmi          ###   ########.fr       */
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
		perror("open");
	width = 0;
	line = get_next_line(fd);
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *matrix_line, char *line)
{
	char	**nbrs;
	int		col;

	nbrs = ft_split(line, ' ');
	col = 0;
	while (nbrs[col])
	{
		matrix_line[col] = ft_atoi(nbrs[col]);
		free(nbrs[col]);
		col++;
	}
	free(nbrs[col]);
}

int	**ft_matrix(char *file)
{
	int		**matrix;
	int		fd;
	int		line_count;
	char	*line;

	matrix = (int **)malloc(get_height(file) * sizeof(int *));
	line_count = 0;
	while (line_count < get_height(file))
		matrix[line_count++] = (int *)malloc(get_width(file)
				* sizeof(int));
	fd = open(file, O_RDONLY);
	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_matrix(matrix[line_count], line);
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	free(line);
	close(fd);
	matrix[line_count] = 0;
	return (matrix);
}

// int main(int argc, char **argv)
// {
// 	int x;
// 	int y;
// 	int **matrix;

// 	matrix = ft_matrix(argv[1]);
// 	x = 0;
// 	while (x < get_height(argv[1]))
// 	{
// 		y = 0;
// 		while (y < get_width(argv[1]) - 1)
// 		{
// 			printf("%3d", matrix[x][y]);
// 			y++;
// 		}
// 		printf("\n");
// 		x++;
// 	}
// }