/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:26:03 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 03:13:10 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int			i;
	int			j;
	char		*res;
	long long	c;

	j = 0;
	i = ft_cnt(n);
	c = (long long)n;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	if (c < 0)
	{
		res[j++] = '-';
		c *= -1;
	}
	while (i > j)
	{
		res[i - 1] = ((c % 10) + '0');
		c /= 10;
		i--;
	}
	return (res);
}
