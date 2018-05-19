/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:55:34 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/08 22:20:51 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*s;

	i = 0;
	c = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i < n)
	{
		if (c[i] != s[i])
			return (c[i] - s[i]);
		i++;
	}
	return (0);
}
