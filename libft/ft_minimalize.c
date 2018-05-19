/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:08:00 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/13 21:08:00 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_whtspcs(char *r)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (r[i])
	{
		if (r[i] == ' ')
		{
			while (r[i + 1] == ' ')
				i++;
		}
		r[c] = r[i];
		c++;
		i++;
	}
	r[c] = '\0';
	return (r);
}

static char	*ft_skipendl(char *r)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (r[i])
	{
		while (r[i] == '\n' || r[i] == '\t')
		{
			i++;
		}
		r[c] = r[i];
		c++;
		i++;
	}
	r[c] = '\0';
	return (r);
}

void		ft_minimalize(char *inp)
{
	char	*r;

	if (inp == NULL)
		return ;
	ft_delcomm(inp);
	r = ft_read(inp);
	r = ft_skipendl(r);
	r = ft_whtspcs(r);
	ft_rewrite(inp, r);
	free(r);
}
