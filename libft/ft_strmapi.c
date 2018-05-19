/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:10:23 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 03:06:33 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s1;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s1 = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s1 != NULL)
	{
		while (s[i])
		{
			s1[i] = f(i, s[i]);
			i++;
		}
		s1[i] = '\0';
		return (s1);
	}
	return (NULL);
}
