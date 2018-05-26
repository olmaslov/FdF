/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:24:44 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 03:06:56 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s1 != NULL)
	{
		while (s[i])
		{
			s1[i] = f(s[i]);
			i++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return (NULL);
}
