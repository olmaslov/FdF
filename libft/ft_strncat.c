/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:14:11 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/09 12:57:53 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t x;
	size_t y;
	size_t k;

	x = ft_strlen(s1);
	k = ft_strlen(s2);
	y = 0;
	while (y < k && y < n)
	{
		s1[x++] = *s2++;
		y++;
	}
	s1[x++] = '\0';
	return (s1);
}
