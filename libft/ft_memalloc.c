/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:06:45 by omaslov           #+#    #+#             */
/*   Updated: 2017/10/29 17:53:05 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *alloc;

	alloc = (void *)malloc(sizeof(void) * size);
	if (alloc != NULL)
	{
		ft_bzero(alloc, size);
		return (alloc);
	}
	return (NULL);
}
