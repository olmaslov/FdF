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

static int	hex_and_space(char *line)
{
	int	i;

	i = 0;
	if (line[i] == ',')
	{
		i++;
		if (ft_atoi_hex(line + i) >= 0)
			i += 8;
		else
			return (0);
	}
	if (line[i] == ' ' || line[i] == '-')
		i++;
	else if (line[i])
		return (0);
	return (i);
}

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
		if (line[i] == '-' && !(line[i + 1] > 47 && line[i + 1] < 58))
			return (0);
		if (line[i] > 47 && line[i] < 58)
		{
			while (line[i + 1] > 47 && line[i + 1] < 58)
				i++;
			clp++;
			i++;
		}
		i += hex_and_space(line + i);
	}
	return (clp);
}

void		read_file(t_mlx *mlx, int tmpclp, int height)
{
	int		fd;
	char	*tmpln;
	int		cp_ret;

	fd = open(mlx->file, O_RDONLY);
	mlx->line = "";
	tmpln = NULL;
	while (get_next_line(fd, &(tmpln)) > 0)
	{
		cp_ret = count_points(tmpln);
		if (tmpclp == 0 && cp_ret != 0)
			tmpclp = cp_ret;
		else if (cp_ret == 0 || tmpclp != cp_ret)
			exit(write(1, "Map error", 9));
		tmpln = ft_join(tmpln, " ", 1, 0);
		mlx->line = ft_join(mlx->line, tmpln, 1, 1);
		height++;
	}
	if (!tmpln)
		exit(write(1, "FILE ERROR\n", 10));
	mlx->width = tmpclp;
	mlx->height = height;
}
