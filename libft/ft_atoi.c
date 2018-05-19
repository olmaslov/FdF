/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:53:00 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 06:52:15 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		a;
	long long	i;
	int			r;

	i = 0;
	a = 0;
	r = 1;
	while (str[a] == 32 || (str[a] > 8 && str[a] < 14))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		r = str[a] == '-' ? -1 : 1;
		a++;
	}
	while (str[a] > 47 && str[a] < 58)
	{
		if (i * 10 + (str[a] - 48) < i)
			return (r == 1 ? -1 : 0);
		i = i * 10 + (str[a] - 48);
		a++;
	}
	return ((int)i * r);
}
