/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:10:44 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/09 13:19:23 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
//	char	*s1;
	size_t	sz;

//	s1 = (char *)s;
	sz = ft_strlen(s) + 1;
	return ((char *)ft_memchr((void *)s, c, sz));
}
