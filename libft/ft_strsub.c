/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:59:01 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/08 17:13:04 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;
	size_t	c;

	i = start;
	c = 0;
	if (s == NULL)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * (len) + 1);
	if (s1 != NULL)
	{
		while (c < len)
		{
			s1[c] = s[i];
			i++;
			c++;
		}
		s1[c] = '\0';
		return (s1);
	}
	return (NULL);
}
