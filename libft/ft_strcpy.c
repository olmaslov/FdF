/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:22:37 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 03:05:47 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *s;

	s = dst;
	while (*src != '\0')
		*s++ = *src++;
	*s++ = '\0';
	return (dst);
}
