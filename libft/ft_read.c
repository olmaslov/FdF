/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <omaslov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:20:00 by omaslov           #+#    #+#             */
/*   Updated: 2017/11/13 16:20:00 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

#define BUF_SIZE 1

static int	ft_buffcnt(char *inp)
{
	char	buf1[BUF_SIZE];
	int		len;
	int		fd;

	len = 0;
	if (!(fd = open(inp, O_RDONLY)))
		ft_putstr("Open error");
	while ((read(fd, buf1, BUF_SIZE)) != 0)
		len++;
	close(fd);
	return (len);
}

char		*ft_read(char *inp)
{
	char	buf1[BUF_SIZE];
	char	*buff;
	int		ret;
	int		fd;

	if (inp == NULL)
		return (NULL);
	ret = 0;
	buff = malloc(sizeof(char) * (ft_buffcnt(inp) * BUF_SIZE) + 1);
	if (buff == NULL)
		return (NULL);
	if (!(fd = open(inp, O_RDONLY)))
	{
		ft_putstr("Open error");
		free(buff);
		return (NULL);
	}
	while (read(fd, buf1, BUF_SIZE))
	{
		buff[ret] = buf1[0];
		ret++;
	}
	return (buff);
}
