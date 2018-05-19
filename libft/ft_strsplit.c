/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:59:31 by ollevyts          #+#    #+#             */
/*   Updated: 2017/11/11 00:40:43 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_cwords(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	size_t	ft_lword(char const *s, char c, size_t n)
{
	size_t i;
	size_t count;
	size_t k;

	i = 0;
	k = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		if (count == n)
		{
			while (s[i] != c)
			{
				k++;
				if (i == 0)
					return (k);
				i--;
			}
			return (k);
		}
		i++;
	}
	return (0);
}

static	char	**ft_fill(char const *s, char c, char **res)
{
	size_t i;
	size_t j;
	size_t count;
	size_t word;

	i = 0;
	word = 1;
	count = 0;
	while (word <= ft_cwords(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		count++;
		if (count == word)
		{
			while (j < ft_lword(s, c, word))
				res[word - 1][j++] = s[i++];
		}
		res[word - 1][j] = '\0';
		word++;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	sz;
	size_t	sw;

	i = 0;
	if (s == NULL)
		return (NULL);
	sz = ft_cwords(s, c) + 1;
	res = (char **)malloc(sizeof(char *) * sz);
	if (res == NULL)
		return (NULL);
	while (i < ft_cwords(s, c))
	{
		sw = (ft_lword(s, c, i + 1) + 1);
		res[i] = (char *)malloc(sizeof(char) * sw);
		if (res[i] == NULL)
			return (NULL);
		i++;
	}
	res[i] = NULL;
	res = ft_fill(s, c, res);
	return (res);
}
