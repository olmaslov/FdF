/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 18:26:50 by omaslov           #+#    #+#             */
/*   Updated: 2018/02/18 15:47:54 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_file
{
	int				fd;
	int				ret;
	char			*cont;
	char			*cnw;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	struct s_file	*next;
}					t_file;

#endif
