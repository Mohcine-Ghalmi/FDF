/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:30:19 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/03 17:04:36 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	int	index_hexa(int c)
{
	long int	i;
	char		*hexa;

	hexa = "0123456789ABCDEF";
	i = 0;
	c = ft_toupper(c);
	while (hexa[i])
	{
		if (hexa[i] == c)
			return (i);
		i++;
	}
	exit(1);
}

long	int	ft_atoi_base(char *color)
{
	size_t		i;
	long int	sum;
	long int	n;

	i = ft_strlen(color);
	sum = 0;
	n = 1;
	while (--i > 0)
	{
		sum += index_hexa(color[i]) * n;
		n *= 16;
	}
	return (sum);
}
