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

	tmpclp = 0;
	tmpln = NULL;
	fd = open(mlx->file, O_RDONLY);
	mlx->line[0] = '\0';
	while (get_next_line(fd, &(tmpln)) > 0)
	{
		if (tmpclp == 0)
			tmpclp = count_points(tmpln);
		else if (tmpclp != count_points(tmpln))
			exit(write(1, "Map error", 9));
		ft_strcat(mlx->line, tmpln);
		mlx->width = tmpclp;
	}
	printf("%s\n", mlx->line);
	if (!tmpln)
		exit(write(1, "FILE ERROR\n", 10));
}