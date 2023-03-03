/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:41:18 by mghalmi           #+#    #+#             */
/*   Updated: 2023/03/03 16:49:02 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"

long int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int	    count_words(char const *s, char c);
int	    ft_isprint(int c);
int	    ft_toupper(int c);
long int     ft_atoi_base(char *color);

#endif
