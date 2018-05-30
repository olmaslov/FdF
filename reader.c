#include "fdf.h"

static int	count_points(char *line)
{
	int clp;
	int i;

	i = 0;
	clp = 0;
	while (line[i])
	{
		if (line[i] > 47 && line[i] < 58)
		{
			while (line[i + 1] > 47 && line[i + 1] < 58)
				i++;
			clp++;
		}
		if (line[i] == ',')
			i += 9;
		i++;
	}
	return (clp);
}

void		read_file(t_mlx *mlx)
{
	int		fd;
	int		tmpclp;
	int 	height;
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
		tmpln = ft_strjoin(tmpln, " ");
		mlx->line = ft_strjoin(mlx->line, tmpln);
		height++;
	}
	mlx->width = tmpclp;
	mlx->height = height;
	if (!tmpln)
		exit(write(1, "FILE ERROR\n", 10));
}
