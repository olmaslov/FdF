/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:47:23 by omaslov           #+#    #+#             */
/*   Updated: 2018/06/05 13:47:25 by omaslov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_points(char *line)
{
	int clp;
	int i;
	int	sl;

	i = 0;
	clp = 0;
	sl = (int)ft_strlen(line);
	while (i < sl)
	{
		if (line[i] == '-')
			i++;
		if (line[i] > 47 && line[i] < 58)
		{
			while (line[i + 1] > 47 && line[i + 1] < 58)
				i++;
			clp++;
		}
		if (line[i] == ',')
			while (line[i + 1] != ' ')
				i++;
		i++;
	}
	return (clp);
}

void		read_file(t_mlx *mlx)
{
	int		fd;
	int		tmpclp;
	int		height;
	char	*tmpln;

	tmpclp = 0;
	height = 0;
	fd = open(mlx->file, O_RDONLY);
	mlx->line = "";
	while (get_next_line(fd, &(tmpln)) > 0)
	{
		if (tmpclp == 0)
			tmpclp = count_points(tmpln);
		else if (tmpclp != count_points(tmpln))
			exit(write(1, "Map error", 9));
		tmpln = ft_join(tmpln, " ", 1, 0);
		mlx->line = ft_join(mlx->line, tmpln, 1, 1);
		height++;
	}
	mlx->width = tmpclp;
	mlx->height = height;
	if (!tmpln)
		exit(write(1, "FILE ERROR\n", 10));
}
