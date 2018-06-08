/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 22:39:19 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/07 22:39:25 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi_hex(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (str[0] == 48 && str[1] == 120)
		i = 2;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 102)
			nb = (nb * 16) + (str[i] - 87);
		else if (str[i] >= 48 && str[i] <= 57)
			nb = (nb * 16) + (str[i] - 48);
		else if (str[i] >= 65 && str[i] <= 70)
			nb = (nb * 16) + (str[i] - 55);
		else
			break ;
		i++;
	}
	if (i == 8)
		return (nb);
	else
		return (-1);
}
