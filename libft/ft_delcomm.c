/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delcomm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:52:00 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/14 16:52:00 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_skipcommtwo(char *r)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (r[i])
	{
		if (r[i] == '/' && r[i + 1] == '*')
		{
			while (!(r[i - 1] == 47 && r[i - 2] == 42))
				i++;
		}
		r[c] = r[i];
		c++;
		i++;
	}
	r[c] = '\0';
	return (r);
}

static char	*ft_skipcomm(char *r)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (r[i])
	{
		if (r[i] == '/' && r[i + 1] == '/' && r[i - 1] != '"')
		{
			while (r[i] != '\n')
				i++;
		}
		r[c] = r[i];
		c++;
		i++;
	}
	r[c] = '\0';
	return (r);
}

void		ft_delcomm(char *inp)
{
	char *r;

	if (inp == NULL)
		return ;
	r = ft_read(inp);
	r = ft_skipcomm(r);
	r = ft_skipcommtwo(r);
	ft_rewrite(inp, r);
}
