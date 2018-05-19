/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:39:32 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 00:26:17 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = i;
		k = 0;
		while (needle[k] == haystack[j] && j < len)
		{
			k++;
			j++;
			if (needle[k] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
