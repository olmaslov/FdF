/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:29:05 by omaslov           #+#    #+#             */
/*   Updated: 2017/10/27 21:11:09 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t x;

	x = ft_strlen(s1);
	while (*s2 != '\0')
		s1[x++] = *s2++;
	s1[x++] = '\0';
	return (s1);
}
