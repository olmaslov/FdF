/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:34:00 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/13 20:34:00 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_writeendl(char *inp, char *wr)
{
	int		fd;
	char	*ns;
	char	*buf;

	buf = ft_read(inp);
	ns = ft_strcat(buf, wr);
	if (inp == NULL || wr == NULL)
		return ;
	if (!(fd = open(inp, O_WRONLY)))
		ft_putstr("Error");
	if (write(fd, ns, ft_strlen(ns)))
	{
		ft_putchar_fd('\n', fd);
		ft_putstr("Write success!");
	}
	free(buf);
}
