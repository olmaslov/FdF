/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:48:05 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 00:14:03 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t last;

	i = 0;
	if (dstsize < ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (dst[i] && i < dstsize)
		i++;
	last = i;
	while (src[i - last] && i < dstsize - 1)
	{
		dst[i] = src[i - last];
		i++;
	}
	if (last < dstsize)
		dst[i] = '\0';
	return (last + ft_strlen(src));
}
