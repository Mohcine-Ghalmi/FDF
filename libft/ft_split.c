/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:51:03 by mghalmi           #+#    #+#             */
/*   Updated: 2023/02/25 13:02:56 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *line, char c)
{
	int	width;
	int	i;
	int	word;

	width = 0;
	word = 1;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			word = 1;
		if (line[i] != c && line[i] != '\n' && word)
		{
			width++;
			word = 0;
		}
		i++;
	}
	return (width);
}

int	word_size(char const *s, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		wc++;
		i++;
	}
	return (wc);
}

void	*ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	*words(char const *s, char c)
{
	int		wrld_len;
	int		i;
	char	*word;

	i = 0;
	wrld_len = word_size(s, c);
	word = malloc(sizeof(char) * (wrld_len + 1));
	if (!word)
		return (NULL);
	while (i < wrld_len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			str[j++] = words(&s[i++], c);
		if (j > 0 && !s[j - 1])
			return (ft_free(str));
		while (s[i] && s[i] != c)
			i++;
	}
	str[j] = 0;
	return (str);
}
