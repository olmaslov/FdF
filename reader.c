//
// Created by Oleksii MASLOV on 5/19/18.
//

#include "fdf.h"

static int	count_points(char *line)
{
	int clp;

	clp = 0;
	while (*line++)
	{
		if (*line > 47 && *line < 58)
		{
			while (*line + 1 > 47 && *line + 1 < 58)
				*line++;
			clp++;
		}
		else if (*line == ',')
			line = &*line + 9;
	}
	return (clp);
}

void		read_file(t_mlx *mlx)
{
	int		fd;
	int 	tmpclp;
	char	*tmpln;
	char	*tmpln2;

	tmpclp = 0;
	tmpln = ft_strnew(10);
	fd = open(mlx->file, O_RDONLY);
	while (get_next_line(fd, &(tmpln)) > 0)
	{
		if (tmpclp == 0)
			tmpclp = count_points(tmpln);
		else if (tmpclp != count_points(tmpln))
			exit(write(1, "Map error", 9));
		ft_strcat(tmpln, " ");
		if (tmpln2[0] == '\0')
			ft_strcpy(tmpln2, tmpln);
		else
			ft_strcat(tmpln2, tmpln);
		mlx->width = tmpclp;
	}
	mlx->line = ft_strnew(ft_strlen(tmpln2));
	ft_strcat(mlx->line, tmpln2);
	printf("%s\n", mlx->line);
//	if (!tmpln)
//		exit(write(1, "FILE ERROR\n", 10));
}