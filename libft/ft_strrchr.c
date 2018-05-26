/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:14:05 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 01:00:19 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)s;
	while (*s++)
		i++;
	while (i >= 0)
	{
		if ((int)s1[i] == c)
			return (s1 + i);
		i--;
	}
	return (NULL);
}
