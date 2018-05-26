/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:50:00 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/13 18:50:00 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_rewrite(char *inp, char *wr)
{
	int		fd;

	if (inp == NULL || wr == NULL)
		return ;
	if (!(fd = open(inp, O_TRUNC | O_WRONLY)))
		ft_putstr("Open error");
	if (write(fd, wr, ft_strlen(wr)))
		ft_putstr("Write success!");
}
