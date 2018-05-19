/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 05:36:59 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 05:58:34 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst == NULL || del == NULL || alst == NULL)
		return ;
	if ((*alst)->next == NULL)
	{
		ft_lstdelone(alst, del);
		return ;
	}
	ft_lstdel(&(*alst)->next, del);
	ft_lstdelone(alst, del);
}
