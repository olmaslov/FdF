/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 06:15:16 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/11 06:55:06 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	if (lst->next == NULL)
	{
		new = (*f)(lst);
		return (new);
	}
	new = (*f)(lst);
	new->next = ft_lstmap(lst->next, f);
	return (new);
}
