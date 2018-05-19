/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:27:09 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/08 21:13:55 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sc;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sc = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (sc != NULL)
	{
		ft_strcat(sc, s1);
		ft_strcat(sc, s2);
		return (sc);
	}
	return (NULL);
}
