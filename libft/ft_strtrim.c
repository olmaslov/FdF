/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:50:23 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 03:08:49 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	int		a;
	char	*sr;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	l = ft_strlen(s);
	while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
		l--;
	a = 0;
	sr = (char *)malloc(sizeof(char) * i == ft_strlen(s) ?
	1 : (l - i) + 1);
	if (sr != NULL)
	{
		while (i != l && i < l)
			sr[a++] = s[i++];
		sr[a] = '\0';
		return (sr);
	}
	return (NULL);
}
