/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 22:12:02 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/07 22:12:06 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_join(char *s1, char *s2, int k1, int k2)
{
	char	*sc;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sc = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (sc != NULL)
	{
		ft_strcat(sc, s1);
		ft_strcat(sc, s2);
		if (k1 && s1[0])
			free(s1);
		if (k2 && s2[0])
			free(s2);
		return (sc);
	}
	return (NULL);
}
