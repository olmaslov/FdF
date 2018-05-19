/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:10:46 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/08 22:35:54 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	siz;
	char	*copy;

	siz = ft_strlen(s1) + 1;
	if ((copy = (char *)malloc(sizeof(char) * siz)) == NULL)
		return (NULL);
	ft_strcpy(copy, s1);
	return (copy);
}
