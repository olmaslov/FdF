/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:26:37 by omaslov           #+#    #+#             */
/*   Updated: 2018/01/04 18:26:40 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			writeln(t_file **tmp, char ***line)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while ((*tmp)->tmp[i] && (*tmp)->tmp[i] != '\n' && (*tmp)->tmp != '\0')
		i++;
	if ((*tmp)->tmp[i] == '\n')
		j = 1;
	**line = ft_strsub((*tmp)->tmp, 0, i);
	(*tmp)->cont = **line;
	(*tmp)->cont = ft_strsub((*tmp)->tmp, i + 1,
								(ft_strlen((*tmp)->tmp) - i));
	free((*tmp)->tmp);
	(*tmp)->tmp = (*tmp)->cont;
	return (j == 1 ? 1 : 0);
}

static t_file		*ft_listing(t_file **list, int fd)
{
	t_file			*n;
	t_file			*k;

	n = *list;
	while ((*list) != NULL)
	{
		if ((*list)->fd == fd)
		{
			k = *list;
			*list = n;
			return (k);
		}
		*list = (*list)->next;
	}
	k = (t_file*)malloc(sizeof(t_file));
	k->fd = fd;
	k->tmp = NULL;
	*list = k;
	k->next = n;
	return (k);
}

static int			writebuf(t_file **t, char ***line)
{
	int				i;

	i = 0;
	if (ft_strchr((*t)->buf, '\n') == NULL)
	{
		(*t)->cont = ft_strjoin(**line ? **line : "", (*t)->buf);
		**line ? free(**line) : **line;
		**line = (*t)->cont;
		ft_bzero((*t)->buf, BUFF_SIZE + 1);
		return (0);
	}
	else
	{
		while ((*t)->buf[i] != '\n' && (*t)->buf[i] != '\0')
			i++;
		(*t)->cnw = (ft_strsub((*t)->buf, 0, i));
		(*t)->cont = ft_strjoin(**line ? **line : "", (*t)->cnw);
		free((*t)->cnw);
		**line ? free(**line) : **line;
		**line = (*t)->cont;
		(*t)->cont = ft_strsub((*t)->buf, (i + 1), (ft_strlen((*t)->buf) - i));
		(*t)->tmp ? free((*t)->tmp) : (*t)->tmp;
		(*t)->tmp = (*t)->cont;
		return (1);
	}
}

int					get_next_line(const int fd, char **line)
{
	static t_file	*fl;
	t_file			*tmp;

	tmp = ft_listing(&fl, fd);
	ft_bzero(tmp->buf, BUFF_SIZE + 1);
	tmp->ret = 1;
	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, tmp->buf, 0) < 0)
		return (-1);
	*line = NULL;
	if (tmp->tmp != NULL && tmp->tmp[0] != '\0')
		if (writeln(&tmp, &line) == 1)
			return (1);
	while (tmp->ret > 0 || tmp->buf[0] != '\0')
	{
		tmp->ret = (int)read(fd, tmp->buf, BUFF_SIZE);
		if (writebuf(&tmp, &line) == 1)
			return (1);
	}
	if (tmp->ret != 0 || (*line)[0] == '\0')
	{
		free(tmp->cont);
		return (tmp->ret == 0 ? 0 : -1);
	}
	else
		return (1);
}
