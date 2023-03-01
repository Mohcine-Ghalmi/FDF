/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:30:19 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/01 17:40:32 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int index_hexa(int c)
{
    int i;
    char    *hexa;

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

int ft_atoi_base(char *color)
{
    size_t i;
    int sum;
    int n;
    
    i = ft_strlen(color);
    sum = 0;
    n = 1;
    while (--i > 0)
    {
        sum += index_hexa(color[i]) * n;
        n *= 16;
    }
    return sum;
}
